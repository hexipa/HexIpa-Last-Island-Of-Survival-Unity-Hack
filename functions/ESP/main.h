#include <vector>
#include <chrono>
#import "functions/ESP/struct.h"
#define kWidth  [UIScreen mainScreen].bounds.size.width
#define kHeight [UIScreen mainScreen].bounds.size.height

using namespace IL2CPP;
using namespace std;

bool checker;
bool Mchecker;
bool MineChecker;



float clappedFloat = 100.0f;
float topPosFloat = 1.82f;
float botPosFloat = 0.1f;
float calculatedPositionFloat = 2.2f;



float BonesColor[4] = {255,255,255,255};

monoArray<uintptr_t> *objects;
void *Battle;
void *MonsterMgr;
//vector<uintptr_t> players;
vector<EnemyInfo> enemyInfo;

class HexIpa_t{

public:
void init();
Vector3(*position)(void*);
void*(*transform)(void*);
monoArray<uintptr_t>*(*find_objects)(void*);
void*(*get_type)(monoString*);
void*(*camera)();
Vector3(*world_to_viewport)(void*, Vector3);
monoString*(*get_name)(void*);
monoString*(*get_name2)(void*);
void*(*get_PInfo)(void*);
void*(*find_object)(void*);
bool(*isAlive)(void*);
//Bounds(*get_bounds)(void*);
void*(*get_rigidbody)(void*);
void(*set_detectCollisions)(void*, bool);
void(*set_position)(void*, Vector3);
//void(*run)(void*, Vector3);
//void(*rotate_cam)(void*, Vector3);

ImVec2 w2s(Vector3);
ImVec2 w_checker(Vector3, bool&);
};
HexIpa_t* HexIpa = new HexIpa_t();

void HexIpa_t::init(){

this->position = (Vector3 (*)(void*))getRealOffset(GetPositionOffset);
this->transform = (void* (*)(void*))getRealOffset(GetTransformOffset);
this->get_type = (void* (*)(monoString*))getRealOffset(GetTypeOffset);
this->find_objects = (monoArray<uintptr_t>* (*)(void*))getRealOffset(FindObjectsOffset);
this->camera = (void* (*)())getRealOffset(CameraOffset);
this->world_to_viewport = (Vector3 (*)(void*, Vector3))getRealOffset(W2WPOffset);
this->get_name = (monoString* (*)(void*))getRealOffset(GetNameOffset);//0x26F7910
this->get_name2 = (monoString* (*)(void*))getRealOffset(GetName2Offset);
this->get_PInfo = (void *(*)(void*))getRealOffset(GetPlayerInfoOffset);
this->find_object = (void* (*)(void*))getRealOffset(FindObjectOffset);
this->isAlive = (bool (*)(void*))getRealOffset(IsAliveObjectOffset);
//this->get_bounds = (Bounds (*)(void*))getRealOffset(ENC(0x26D30DC));
this->get_rigidbody = (void *(*)(void*))getRealOffset(GetRigidbodyOffset);
this->set_detectCollisions = (void (*)(void*, bool))getRealOffset(SetDetectCollisionsOffset);
this->set_position = (void (*)(void*, Vector3))getRealOffset(SetPositionOffset);
//this->run = (void (*)(void*, Vector3))getRealOffset(ENC(0x102D9D0));
//this->rotate_cam = (void (*)(void*, Vector3))getRealOffset(ENC(0xBF1C70));

}



ImVec2 HexIpa_t::w2s(Vector3 pos) {        
    auto cam = HexIpa->camera();
    if(!cam)return {0,0};
    Vector3 worldPoint = HexIpa->world_to_viewport(cam, pos);
    Vector3 location;
    int ScreenWidth = kWidth;
    int ScreenHeight = kHeight;
    location.x = ScreenWidth * worldPoint.x;
    location.y = ScreenHeight - worldPoint.y * ScreenHeight;
    location.z = worldPoint.z;
    return {location.x, location.y};
}
    
ImVec2 HexIpa_t::w_checker(Vector3 pos, bool &checker) {
    auto cam = HexIpa->camera();
    if(!cam)return {0,0};
    Vector3 worldPoint = HexIpa->world_to_viewport(cam, pos);
    Vector3 location;
    int ScreenWidth = ImGui::GetIO().DisplaySize.x;
    int ScreenHeight = ImGui::GetIO().DisplaySize.y;
    location.x = ScreenWidth * worldPoint.x;
    location.y = ScreenHeight - worldPoint.y * ScreenHeight;
    location.z = worldPoint.z;
    checker = location.z > 1;
    return {location.x, location.y};
}

static void DrawBoneToBone(void *bone1, void *bone2, ImColor Color)
{
ImDrawList* draw_list1 = ImGui::GetBackgroundDrawList();
    if(bone1 != nullptr && bone2 != nullptr)
    {
        Vector3 boneposition = HexIpa->position(HexIpa->transform(bone1));
        Vector3 boneposition2 = HexIpa->position(HexIpa->transform(bone2));
        ImVec2 w2sboneposition = HexIpa->w2s(boneposition);
        ImVec2 w2sboneposition2 = HexIpa->w2s(boneposition2);
        
        draw_list1->AddLine(ImVec2(w2sboneposition.x, w2sboneposition.y), ImVec2(w2sboneposition2.x, w2sboneposition2.y), Color);
        
    }
}

const void DrawBones(monoArray<void **>* Parts, const std::vector<std::pair<int, int>>& connections, ImColor color) {
    ImDrawList* draw_list = ImGui::GetBackgroundDrawList();
    for (const auto& [index1, index2] : connections) {
        if (Parts->getPointer()[index1] && Parts->getPointer()[index2]) {
            Vector3 pos1 = HexIpa->position(HexIpa->transform(Parts->getPointer()[index1]));
            Vector3 pos2 = HexIpa->position(HexIpa->transform(Parts->getPointer()[index2]));
            ImVec2 w2s1 = HexIpa->w2s(pos1);
            ImVec2 w2s2 = HexIpa->w2s(pos2);
            draw_list->AddLine(w2s1, w2s2, color);
        }
    }
}

void RenderLine(const ImVec2& from, const ImVec2& to, ImColor Color, float thickness)
{
ImDrawList* draw_list = ImGui::GetBackgroundDrawList();

	draw_list->AddLine(from, to, Color, thickness);
}

void UpdateEnemyInfo(const EnemyInfo& newEnemy) {
    auto it = std::find_if(enemyInfo.begin(), enemyInfo.end(),
                           [&](const EnemyInfo& enemy) {
                               return enemy.Name == newEnemy.Name;
                           });

    if (it != enemyInfo.end()) {
        it->pos = newEnemy.pos;
        it->Hp = newEnemy.Hp;
        it->MaxHp = newEnemy.MaxHp;
    } else {
        enemyInfo.push_back(newEnemy);
    }
}

void startesp() {
    ImDrawList* bg = ImGui::GetBackgroundDrawList();
    if(ESP.Draw){
    //objects = HexIpa->find_objects(HexIpa->get_type(il2cpp_string_new("OtherPlayerController, Assembly-CSharp")));


    if(Battle == nullptr){
        Battle = HexIpa->find_object(HexIpa->get_type(il2cpp_string_new(ENC("Battle, Assembly-CSharp"))));
    }
    if(MonsterMgr == nullptr){
        MonsterMgr = HexIpa->find_object(HexIpa->get_type(il2cpp_string_new(ENC("MonsterMgr, Assembly-CSharp"))));
    }
    if(me->ptr == nullptr){
        me->ptr = HexIpa->find_object(HexIpa->get_type(il2cpp_string_new(ENC("PlayerController, Assembly-CSharp"))));
    }

    monoDictionary2<long*, void **> *monsters = nullptr;

    //players = objects->toCPPlist();
    if(Battle != nullptr){
        monoDictionary2<long*, void **> *players = *(monoDictionary2<long*, void **> **)((uint64_t)Battle + ENC(0x58));


        monoDictionary2<long*, void **> *mine = *(monoDictionary2<long*, void **> **)((uint64_t)Battle + ENC(0x198));

        if(MonsterESP.Draw){
            monsters = *(monoDictionary2<long*, void **> **)((uint64_t)MonsterMgr + ENC(0x20));
        }

      if(players != nullptr){

        for(int i = 0; i < players->getSize(); i++){

            enemy->ptr = reinterpret_cast<void *>(players->getValues()[i]);
            if(!enemy->ptr||!HexIpa->isAlive(enemy->ptr)){
                continue;
            }
            void *enemyptr = enemy->ptr;
            enemy->trans = HexIpa->transform(enemyptr);
            enemy->pos = HexIpa->position(enemy->trans);
            enemy->w2spos = HexIpa->w_checker(enemy->pos, checker);
            enemy->playerinfo = HexIpa->get_PInfo(enemyptr);
            enemy->w2stop = HexIpa->w2s(HexIpa->position(*(void **)((uint64_t)enemy->ptr + ENC(0x80))));
            enemy->Hp = *(int*)((uint64_t)enemy->ptr + ENC(0x110));

            enemy->MaxHp = *(int*)((uint64_t)enemy->playerinfo + ENC(0x68));
            monoString *NameTmp = HexIpa->get_name(enemy->ptr);
            enemy->Name = NameTmp->toCPPString();
            int Dist = Vector3::Distance(me->pos, enemy->pos);

            EnemyInfo temp;
            temp.pos = enemy->pos;
            temp.Hp = enemy->Hp;
            temp.MaxHp = enemy->MaxHp;
            temp.Name = enemy->Name;
            UpdateEnemyInfo(temp);

            if(enemy->Hp <= 0){
                continue;
            }
            me->trans = HexIpa->transform(me->ptr);
            me->pos = HexIpa->position(me->trans);
            me->rigid = HexIpa->get_rigidbody(me->ptr);
            me->cam = *(void **)((uint64_t)Battle + ENC(0x28));

            //const float &clapped_distance = Dist / 90.f;
            //const float &clapped = clapped_distance / 90.f;

            const float &clapped_distance = Dist / clappedFloat;
            const float &clapped = clapped_distance / clappedFloat;


            /*ImVec2 top_pos(
                HexIpa->w2s(enemy->pos + Vector3(0, 1.75 + clapped_distance, 0)));

            ImVec2 bot_pos(
                HexIpa->w2s(enemy->pos - Vector3(0, 0.3f + clapped_distance, 0)));*/

            ImVec2 top_pos(
                HexIpa->w2s(enemy->pos + Vector3(0, topPosFloat + clapped_distance, 0)));

            ImVec2 bot_pos(
                HexIpa->w2s(enemy->pos - Vector3(0, botPosFloat + clapped_distance, 0)));


            auto posTop = top_pos.x;
            auto posBottom = bot_pos.x;
            if (top_pos.x > bot_pos.x)
            {
                posTop = bot_pos.x;
                posBottom = top_pos.x;
            }

            //float calculatedPosition = fabs((top_pos.y - bot_pos.y) * (0.0092f / 0.019f) / (2 + clapped));

            float calculatedPosition = fabs((top_pos.y - bot_pos.y) * (0.0092f / 0.019f) / (calculatedPositionFloat + clapped));

            ImRect rect(
                ImVec2(posTop - calculatedPosition - clapped_distance, top_pos.y),
                ImVec2(posBottom + calculatedPosition + clapped_distance, bot_pos.y));

            ImRect Namerect(
                ImVec2(posTop - calculatedPosition * 1.5 - clapped_distance, top_pos.y),
                ImVec2(posTop + calculatedPosition + clapped_distance, bot_pos.y));

            ImRect mirrored_rect(
                ImVec2(posTop - calculatedPosition - clapped_distance, bot_pos.y),
                ImVec2(posBottom + calculatedPosition + clapped_distance, top_pos.y));

            if(checker){

            if(ESP.Line){
                bg->AddLine(enemy->w2stop, {ImGui::GetIO().DisplaySize.x / 2, 0}, ImColor(255,0,0,255));
                bg->AddRect(rect.Min, rect.Max, ImColor(255, 255, 255), 0, 0, 1);
                bg->AddRect(rect.Min - ImVec2(1, 1), rect.Max + ImVec2(1, 1), ImColor(0, 0, 0), 0, 0, 1);
                bg->AddRect(rect.Min + ImVec2(1, 1), rect.Max - ImVec2(1, 1), ImColor(0, 0, 0), 0, 0, 1);
            }
            if(ESP.ZBox){
                bg->AddLine(mirrored_rect.Min, mirrored_rect.Max, ImColor(0, 0, 255), 3);
                bg->AddLine(rect.Min, mirrored_rect.Max, ImColor(255, 255, 255), 3);
                bg->AddLine(rect.Max, mirrored_rect.Min, ImColor(255, 0, 0), 3);
            }
            if(ESP.Hp){
                string HpStr = to_string(enemy->Hp) + ENC("/") + to_string(enemy->MaxHp);
                ImVec2 textSize = ImGui::CalcTextSize(HpStr.c_str());
                ImVec2 health_pos = {
                    rect.Min.x,
                    rect.Max.y};
                bg->AddText(font, 10.0f, ImVec2(health_pos.x, health_pos.y), ImColor(255, 0, 0, 255), HpStr.c_str());


            }
            if(ESP.Bones){
                ImColor BonesColorIm(BonesColor[0], BonesColor[1], BonesColor[2], BonesColor[3]);
                monoArray<void **> *Parts = *(monoArray<void **> **)((uint64_t)enemy->ptr + ENC(0x60));
                std::vector<std::pair<int, int>> connections = {
                    {16, 10}, {15, 2}, {2, 0}, {0, 16}, {14, 3}, {3, 1}, {1, 16},
                    {16, 8}, {8, 11}, {11, 4}, {4, 6}, {6, 12}, {11, 5}, {5, 7}, {7, 13}
                };
                DrawBones(Parts, connections, BonesColorIm);
            }
            if(ESP.Distance){
                string DistString = to_string(Dist) + ENC("M");
                const char *DistStr = DistString.c_str();
                ImVec2 distance_pos = {
                    mirrored_rect.Min.x,
                    mirrored_rect.Max.y};
                bg->AddText(font, 10.0f, distance_pos, IM_COL32(255, 0, 0, 255), DistStr);
            }
            if(ESP.Name){
                ImVec2 textSize = ImGui::CalcTextSize(enemy->Name.c_str());
                ImVec2 name_pos = {
                    Namerect.Min.x,
                    Namerect.Min.y};
                bg->AddText(font, 15.0f, name_pos, IM_COL32(255, 0, 0, 255), enemy->Name.c_str());
            }
            if(ESP.Box3D){             

            }
 
            }
        }
      }

      if(monsters != nullptr){
        if(MonsterESP.Draw){
            for(int i = 0; i < monsters->getSize(); i++){
                enemy->ptr = reinterpret_cast<void *>(monsters->getValues()[i]);
                if(!enemy->ptr||!HexIpa->isAlive(enemy->ptr)){
                    continue;
                }
                enemy->trans = HexIpa->transform(enemy->ptr);
                enemy->pos = HexIpa->position(enemy->trans);
                enemy->w2spos = HexIpa->w_checker(enemy->pos, Mchecker);
                enemy->playerinfo = *(void **)((uint64_t)enemy->ptr + ENC(0x78));
              

              if(Mchecker){

                if(MonsterESP.Line){
                    bg->AddLine(enemy->w2spos, {ImGui::GetIO().DisplaySize.x / 2, 0}, ImColor(255,255,255,255));
                }
                if(MonsterESP.Name){
                    monoString *NameTmp = HexIpa->get_name2(enemy->ptr);
                    enemy->Name = NameTmp->toCPPString();
                    bg->AddText(font, 15.0f, enemy->w2spos, IM_COL32(255, 255, 255, 255), enemy->Name.c_str());
                }

              }
            }
        }
      }

      if(mine != nullptr){
        if(MineESP.Draw){
           for(int i = 0; i < mine->getSize(); i++){
                Mine->ptr = reinterpret_cast<void *>(mine->getValues()[i]);
                if(!Mine->ptr||!HexIpa->isAlive(Mine->ptr)){
                    continue;
                }
                Mine->trans = HexIpa->transform(Mine->ptr);
                Mine->pos = HexIpa->position(Mine->trans);
                Mine->w2spos = HexIpa->w_checker(Mine->pos, MineChecker);

                if(MineChecker){
                    bg->AddLine(Mine->w2spos, {ImGui::GetIO().DisplaySize.x / 2, 0}, ImColor(0,255,0,255));

                    monoString *NameTmp = HexIpa->get_name2(Mine->ptr);
                    Mine->Name = NameTmp->toCPPString();
                    if(Mine->Name == ENC("ore_liuhuangkuang_01(Clone)(Clone)")){
                        Mine->Name = ENC("[Sulfur]");
                    }else if(Mine->Name == ENC("ore_yanshikuang_01(Clone)(Clone)")) {
                        Mine->Name = ENC("[Stone]");
                    }else if(Mine->Name == ENC("ore_tiekuang_01(Clone)(Clone)")) {
                        Mine->Name = ENC("[Iron]");
                    }
                    bg->AddText(font, 25.0f, Mine->w2spos, IM_COL32(255, 255, 255, 255), Mine->Name.c_str());
                    Vector3 newPos = Mine->pos - me->pos;
                    //HexIpa->run(me->ptr, newPos);
                    //HexIpa->rotate_cam(me->cam, Mine->pos);
                }
           }
        }
      }
    }

    }
}