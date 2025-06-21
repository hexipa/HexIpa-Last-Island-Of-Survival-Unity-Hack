//Require standard library
#import <Metal/Metal.h>
#import <MetalKit/MetalKit.h>
#import <Foundation/Foundation.h>
#include <iostream>
#include <fstream>
//Imgui library
#import "Esp/ImGuiDrawView.h"
#import "IMGUI/imgui.h"
#import "IMGUI/imgui_impl_metal.h"
#import "IMGUI/imgui-fokusi.h"
#import "IMGUI/imgui_internal.h"
//Patch library
#import "utils/NakanoIchika.h"
#import "utils/NakanoNino.h"
#import "utils/NakanoMiku.h"
#import "utils/NakanoYotsuba.h" 
#include "utils/oxorany_include.h"
#import "utils/dobby.h"
#import "utils/il2cpp/il2cpp.h"
#import "utils/Vector3.h"
#import "utils/Monostring.h"
//some another helpers
#import "variables.h"
#import "functions/autoupdate.h"
#import "functions/offsets.h"
#import "functions/igg.h"
ImFont *font;
#import "functions/ESP/main.h"
#import "font.h"

#define kWidth  [UIScreen mainScreen].bounds.size.width
#define kHeight [UIScreen mainScreen].bounds.size.height
#define kScale [UIScreen mainScreen].scale


@interface ImGuiDrawView () <MTKViewDelegate>
@property (nonatomic, strong) id <MTLDevice> device;
@property (nonatomic, strong) id <MTLCommandQueue> commandQueue;
@end

@implementation ImGuiDrawView

NSString *appVersion = [[NSBundle mainBundle] objectForInfoDictionaryKey:NSENC("CFBundleShortVersionString")];
NSString *appVersionTrue = NSENC("2.34.0");
NSString *buildVersion = [[NSBundle mainBundle] objectForInfoDictionaryKey:NSENC("CFBundleVersion")];

UIButton *UP,*LOCK,*DOWN,*NOCLIP,*SOUL,*LOGIN;

void Func0079() {
    if (![appVersion isEqualToString:appVersionTrue]) {
        exit(0); 
    }
}

#define Dobby(offset, ptr, orig) DobbyHook(reinterpret_cast<void*>(getRealOffset(offset)), reinterpret_cast<void*>(ptr), reinterpret_cast<void**>(&orig))

- (instancetype)initWithNibName:(nullable NSString *)nibNameOrNil bundle:(nullable NSBundle *)nibBundleOrNil
{
    self = [super initWithNibName:nibNameOrNil bundle:nibBundleOrNil];

    _device = MTLCreateSystemDefaultDevice();
    _commandQueue = [_device newCommandQueue];

    if (!self.device) abort();

    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGuiIO& io = ImGui::GetIO(); (void)io;

    font = io.Fonts->AddFontFromMemoryTTF(font_ttf_otf, font_ttf_otf_len, 27.0f, NULL, io.Fonts->GetGlyphRangesCyrillic());

    io.Fonts->AddFontFromMemoryTTF(font_ttf_otf, font_ttf_otf_len, 25.0f, NULL, io.Fonts->GetGlyphRangesCyrillic());

    ImGui::StyleColorsClassic();
    
    ImGui_ImplMetal_Init(_device);

    return self;
}

+ (void)showChange:(BOOL)open
{
    userInteraction = open;
}

- (MTKView *)mtkView
{
    return (MTKView *)self.view;
}

- (void)loadView
{
    CGFloat w = [UIApplication sharedApplication].windows[0].rootViewController.view.frame.size.width;
    CGFloat h = [UIApplication sharedApplication].windows[0].rootViewController.view.frame.size.height;
    self.view = [[MTKView alloc] initWithFrame:CGRectMake(0, 0, w, h)];
}


- (void)viewDidLoad {

    [super viewDidLoad];
    
    self.mtkView.device = self.device;
    self.mtkView.delegate = self;
    self.mtkView.clearColor = MTLClearColorMake(0, 0, 0, 0);
    self.mtkView.backgroundColor = [UIColor colorWithRed:0 green:0 blue:0 alpha:0];
    self.mtkView.clipsToBounds = YES;


dispatch_async(dispatch_get_global_queue(DISPATCH_QUEUE_PRIORITY_DEFAULT, 0), ^{
    enemy = new enemy_t();
    me = new me_t();
    Mine = new Mine_t();
    initial_setup();
    OpenURL(NSENC("https://t.me/hehipa"));
    HexIpa->init();
    Func0079();

    //pthread_t WorldEditThread;
    //pthread_create(&WorldEditThread, nullptr, WorldEdit, nullptr);
});

}

#pragma mark - Interaction

- (void)updateIOWithTouchEvent:(UIEvent *)event
{
    UITouch *anyTouch = event.allTouches.anyObject;
    CGPoint touchLocation = [anyTouch locationInView:self.view];
    ImGuiIO &io = ImGui::GetIO();
    io.MousePos = ImVec2(touchLocation.x, touchLocation.y);

    BOOL hasActiveTouch = NO;
    for (UITouch *touch in event.allTouches)
    {
        if (touch.phase != UITouchPhaseEnded && touch.phase != UITouchPhaseCancelled)
        {
            hasActiveTouch = YES;
            break;
        }
    }
    io.MouseDown[0] = hasActiveTouch;
}

- (void)touchesBegan:(NSSet<UITouch *> *)touches withEvent:(UIEvent *)event
{
    [self updateIOWithTouchEvent:event];
}

- (void)touchesMoved:(NSSet<UITouch *> *)touches withEvent:(UIEvent *)event
{
    [self updateIOWithTouchEvent:event];
}

- (void)touchesCancelled:(NSSet<UITouch *> *)touches withEvent:(UIEvent *)event
{
    [self updateIOWithTouchEvent:event];
}

- (void)touchesEnded:(NSSet<UITouch *> *)touches withEvent:(UIEvent *)event
{
    [self updateIOWithTouchEvent:event];
}

#pragma mark - MTKViewDelegate

- (void)drawInMTKView:(MTKView*)view
{
    
    ImGuiIO& io = ImGui::GetIO();
    io.DisplaySize.x = view.bounds.size.width;
    io.DisplaySize.y = view.bounds.size.height;

static dispatch_once_t onceToken;
    dispatch_once(&onceToken, ^{
    CGFloat width = kWidth * 0.5;
    CGFloat height = kHeight * 0.5;
    if (kWidth > kHeight) {
        height = kHeight * 0.8;
    } else {
        width = kWidth * 0.8;
    }
    ImGuiIO & io = ImGui::GetIO();

    io.DisplaySize = ImVec2(width + 30, height);
        //ImGui::SetNextWindowPos(ImVec2(0, 0), ImGuiCond_FirstUseEver);
    ImGui::SetNextWindowPos(ImVec2((kWidth - width) * 0.5, (kHeight - height) * 0.5), 0, ImVec2(0, 0));
    ImGui::SetNextWindowSize(ImVec2(io.DisplaySize.x/2, io.DisplaySize.y/2));

    ImGuiStyle* style = &ImGui::GetStyle();

    style->WindowPadding            = ImVec2(15, 15);
    style->WindowRounding           = 12.0f;
    style->FramePadding             = ImVec2(10, 5);
    style->FrameRounding            = 12.0f;
    style->ItemSpacing              = ImVec2(5, 4);
    style->ItemInnerSpacing         = ImVec2(7, 5);
    style->IndentSpacing            = 15.0f;
    style->ScrollbarSize            = 24.0f;
    style->ScrollbarRounding        = 9.0f;
    style->GrabMinSize              = 16.0f; 
    style->GrabRounding             = 3.0f; 
    });

    CGFloat framebufferScale = view.window.screen.scale ?: UIScreen.mainScreen.scale;
    io.DisplayFramebufferScale = ImVec2(framebufferScale, framebufferScale);
    io.DeltaTime = 1 / float(view.preferredFramesPerSecond ?: 120);
    
    id<MTLCommandBuffer> commandBuffer = [self.commandQueue commandBuffer];
    
        
        if (userInteraction == true) {
            [self.view setUserInteractionEnabled:YES];
        } else if (userInteraction == false) {
            [self.view setUserInteractionEnabled:NO];
        }

        MTLRenderPassDescriptor* renderPassDescriptor = view.currentRenderPassDescriptor;
        if (renderPassDescriptor != nil)
        {
            id <MTLRenderCommandEncoder> renderEncoder = [commandBuffer renderCommandEncoderWithDescriptor:renderPassDescriptor];
            [renderEncoder pushDebugGroup:NSENC("ImGui Jane")];

            ImGui_ImplMetal_NewFrame(renderPassDescriptor);
            ImGui::NewFrame();
            
            font = ImGui::GetFont();
            font->Scale = 15.f / font->FontSize;
            
            CGFloat x = (([UIApplication sharedApplication].windows[0].rootViewController.view.frame.size.width) - 360) / 2;
            CGFloat y = (([UIApplication sharedApplication].windows[0].rootViewController.view.frame.size.height) - 300) / 2;
            
            ImGui::SetNextWindowSize(ImVec2(io.DisplaySize.x/2, io.DisplaySize.y/2), ImGuiCond_FirstUseEver);
            
            if (userInteraction)
            {                
               

ImGui::Begin(oxorany("HEXIPA FREE TELEGRAM @hexipahack @jailbreaked"), &userInteraction);

NSString *versionString = [NSString stringWithFormat:NSENC("Game version: %@ (Build %@)"), appVersion, buildVersion];
const char *versionCString = [versionString UTF8String];

ImGui::Text(ENC("%s"), versionCString);

ImGui::RadioButton(ENC("Jailbreak"), &isJb, 1);
ImGui::SameLine();
ImGui::RadioButton(ENC("IPA"), &isJb, 0);

if (ImGui::BeginTabBar(oxorany("HEXIPA"), ImGuiTabBarFlags_NoTooltip|ImGuiTabBarFlags_Reorderable)){
if (ImGui::BeginTabItem(ENCRYPT("Main"))){  
    
if(ImGui::CollapsingHeader(ENCRYPT("Map functions"))){


if(ImGui::Checkbox(ENCRYPT("No textures"), &notexture)){offsetFunc();}
ImGui::SameLine(240);
if(ImGui::Checkbox(ENCRYPT("No tree"), &notree)){offsetFunc();}
ImGui::SameLine(480);
if(ImGui::Checkbox(ENCRYPT("No grass"), &nograss)){offsetFunc();}
if(ImGui::Checkbox(ENCRYPT("Extended build"), &exbuild)){offsetFunc();}
ImGui::SameLine(240);
if(ImGui::Checkbox(ENCRYPT("Lock time"), &locktime)){offsetFunc();}
ImGui::SameLine(480);
if(ImGui::Checkbox(ENCRYPT("Night mode"), &picture)){offsetFunc();}
if(ImGui::Checkbox(ENCRYPT("Instant Explosion"), &instantexp)){offsetFunc();}
ImGui::SameLine(240);
if(ImGui::Checkbox(ENCRYPT("Force build"), &forcebuild)){offsetFunc();}

}
                   

if(ImGui::CollapsingHeader(ENCRYPT("Character functions"))){

ImGui::Checkbox(ENCRYPT("GM"), &gm);
ImGui::SameLine(240);
if(ImGui::Checkbox(ENCRYPT("Name"), &name)){offsetFunc();}
ImGui::SameLine(480);
if(ImGui::Checkbox(ENCRYPT("Fake owner"), &fakeowner)){offsetFunc();}
if(ImGui::Checkbox(ENCRYPT("No fall damage"), &nofalldamage)){offsetFunc();}
ImGui::SameLine(240);
if(ImGui::Checkbox(ENCRYPT("Underwater walk"), &underwater)){offsetFunc();}
ImGui::SameLine(480);
if(ImGui::Checkbox(ENCRYPT("Ignore npc"), &mtt)){offsetFunc();}
if(ImGui::Checkbox(ENCRYPT("No shake"), &noshake)){offsetFunc();}
ImGui::SameLine(240);
if(ImGui::Checkbox(ENCRYPT("Soul"), &soul)){offsetFunc();}

}

if(ImGui::CollapsingHeader(ENCRYPT("Weapon"))){

if(ImGui::Checkbox(ENCRYPT("No recoil"), &norecoil)){offsetFunc();}
ImGui::SameLine(240);
if(ImGui::Checkbox(ENCRYPT("No spread"), &nospread)){offsetFunc();}

}

if(ImGui::Checkbox(ENCRYPT("Bypass"), &bypass)){
//saveoff();
offsetFunc();
}

ImGui::EndTabItem();
   }
}
            
if (ImGui::BeginTabItem(ENCRYPT("IGG"))) {
if (ImGui::CollapsingHeader(ENCRYPT("PVP"))){

if(ImGui::Checkbox(ENCRYPT("Instant RPG"), &instantrpg)){iggFunc();}
ImGui::SameLine(220);
if(ImGui::Checkbox(ENCRYPT("Magic 0.6"), &magic06)){iggFunc();}
ImGui::SameLine(440);
if(ImGui::Checkbox(ENCRYPT("Magic 1.2"), &magic12)){iggFunc();}

if(ImGui::Checkbox(ENCRYPT("Magic 2.0"), &magicbullet)){iggFunc();}
ImGui::SameLine(220);
if(ImGui::Checkbox(ENCRYPT("Magic knife 0.6"), &knife06)){iggFunc();}
ImGui::SameLine(440);
if(ImGui::Checkbox(ENCRYPT("Magic knife 1.2"), &knife12)){iggFunc();}

if(ImGui::Checkbox(ENCRYPT("Magic knife 2.0"), &magicknife)){iggFunc();}
ImGui::SameLine(220);
if(ImGui::Checkbox(ENCRYPT("RAGE Magic"), &magic120)){iggFunc();}
ImGui::SameLine(440);
if(ImGui::Checkbox(ENCRYPT("RAGE Knife"), &knife120)){iggFunc();}

   }

if(ImGui::CollapsingHeader(ENCRYPT("Map function") )){            

if (ImGui::Checkbox(ENCRYPT("Water build" ), &waterbuild)) {iggFunc();}
ImGui::SameLine(220);
if (ImGui::Checkbox(ENCRYPT("Delete map"), &deletemap)) {
   /*if (deletemap) {
      JRMemoryEngine zidanchuantu = JRMemoryEngine(mach_task_self());
      AddrRange range = (AddrRange){0x100000000,0x140000000};
      int32_t search = 10000;
      zidanchuantu.JRScanMemory(range, &search, JR_Search_Type_SInt);
      int32_t Nearsearch = 100;
      zidanchuantu.JRNearBySearch(0x12,&Nearsearch,JR_Search_Type_SInt);
      int32_t Nearsearch1 = 5000;
      zidanchuantu.JRNearBySearch(0x50,&Nearsearch1,JR_Search_Type_SInt);
      int32_t search1 = 5000;
      zidanchuantu.JRScanMemory(range, &search1, JR_Search_Type_SInt);
      vector<void*>results = zidanchuantu.getResults(100);
      int32_t modify = -999;
      for(int i =0;i<results.size();i++){
         zidanchuantu.JRWriteMemory((unsigned long long)(results[i]),&modify,JR_Search_Type_SInt);
         }
      } else {
      JRMemoryEngine zidanchuantu = JRMemoryEngine(mach_task_self());
      AddrRange range = (AddrRange){0x100000000,0x140000000};
      int32_t search = 10000;
      zidanchuantu.JRScanMemory(range, &search, JR_Search_Type_SInt);
      int32_t Nearsearch = 100;
      zidanchuantu.JRNearBySearch(0x12,&Nearsearch,JR_Search_Type_SInt);
      int32_t Nearsearch1 = -999;
      zidanchuantu.JRNearBySearch(0x50,&Nearsearch1,JR_Search_Type_SInt);
      int32_t search1 = -999;
      zidanchuantu.JRScanMemory(range, &search1, JR_Search_Type_SInt);
      vector<void*>results = zidanchuantu.getResults(100);
      int32_t modify = 5000;
      for(int i =0;i<results.size();i++){
         zidanchuantu.JRWriteMemory((unsigned long long)(results[i]),&modify,JR_Search_Type_SInt);
      }
   }*/
}

            

   }
        
        
if(ImGui::CollapsingHeader(ENCRYPT("Character functions"))){

if (ImGui::Checkbox(ENCRYPT("High Fov"), &highfov)) {iggFunc();}
ImGui::SameLine(220);
if (ImGui::Checkbox(ENCRYPT("White Body"), &whitebody)) {iggFunc();}
ImGui::SameLine(440);        
if (ImGui::Checkbox(ENCRYPT("Black Body"), &blackbody)) {iggFunc();}
if (ImGui::Checkbox(ENCRYPT("Fast bike"), &fastbike)){iggFunc();}
ImGui::SameLine(220);
if (ImGui::Checkbox(ENCRYPT("Prevetion Death"), &antideath)){iggFunc();}
ImGui::EndTabItem();

   }
}

if(ImGui::BeginTabItem(ENCRYPT("Misc"))){

if(ImGui::Checkbox(ENCRYPT("Admin ESP(Online players)"), &admesp)){offsetFunc();}ImGui::SameLine(300);
if(ImGui::Checkbox(ENCRYPT("Disable enemy animation"), &noenemyanim)){offsetFunc();}

if(ImGui::Checkbox(ENCRYPT("Disable tracer effect"), &traceroff)){offsetFunc();}ImGui::SameLine(300);
if(ImGui::Checkbox(ENCRYPT("Disable rpg effect"), &rpgoff)){offsetFunc();}

if(ImGui::Checkbox(ENCRYPT("Drink water(lobby)"), &drinkwater)){offsetFunc();}ImGui::SameLine(300);

ImGui::EndTabItem();

}

if(ImGui::BeginTabItem(ENCRYPT("Debug"))){

ImGui::SliderFloat(ENC("clappedFloat"), &clappedFloat, 0.1f, 360.0f, "%.3f");
ImGui::SliderFloat(ENC("topPosFloat"), &topPosFloat, 0.1f, 5.0f, "%.3f");
ImGui::SliderFloat(ENC("botPosFloat"), &botPosFloat, 0.1f, 5.0f, "%.3f");
ImGui::SliderFloat(ENC("calculatedPositionFloat"), &calculatedPositionFloat, 0.1f, 10.0f, "%.3f");


    for(int i = 0; i < enemyInfo.size(); i++){
        ImGui::Text(ENC("%s"), enemyInfo[i].Name.c_str());ImGui::SameLine();
        ImGui::Text(ENC("Position: x:%.2f, y: %.2f, z: %.2f"), enemyInfo[i].pos.x, enemyInfo[i].pos.y, enemyInfo[i].pos.z);ImGui::SameLine();
        ImGui::Text(ENC("Hp: %i/%i"), enemyInfo[i].Hp, enemyInfo[i].MaxHp);
    }

ImGui::EndTabItem();

}

if(ImGui::BeginTabItem(ENCRYPT("ESP"))){

ImGui::Checkbox(ENCRYPT("Draw"), &ESP.Draw);ImGui::SameLine();
ImGui::Checkbox(ENCRYPT("Line"), &ESP.Line);ImGui::SameLine();
ImGui::Checkbox(ENCRYPT("Hp"), &ESP.Hp);
ImGui::Checkbox(ENCRYPT("Distance"), &ESP.Distance);ImGui::SameLine();
ImGui::Checkbox(ENCRYPT("Bones"), &ESP.Bones);ImGui::SameLine();
ImGui::Checkbox(ENCRYPT("Name"), &ESP.Name);
ImGui::Checkbox(ENCRYPT("SVO"), &ESP.ZBox);
ImGui::Dummy(ImVec2(0.0f, 5.0f)); 
ImGui::Checkbox(ENCRYPT("Monster ESP"), &MonsterESP.Draw);
ImGui::Checkbox(ENCRYPT("#Line"), &MonsterESP.Line);
ImGui::Checkbox(ENCRYPT("#Name"), &MonsterESP.Name);
ImGui::Dummy(ImVec2(0.0f, 5.0f));
ImGui::Checkbox(ENCRYPT("Draw mine"), &MineESP.Draw);

//ImGui::Checkbox(ENCRYPT("Hp"), &MonsterESP.Hp);ImGui::SameLine();
//ImGui::Checkbox(ENCRYPT("Distance"), &MonsterESP.Distance);




ImGui::EndTabItem();

}

if(ImGui::BeginTabItem(ENCRYPT("Flying"))){

ImGui::Dummy(ImVec2(0.0f, 5.0f)); 
if(ImGui::Button(ENC("Flying"))){
[self updateButtonColors];
[self Flying];
}
ImGui::SliderInt(ENCRYPT("Height per 1 tap"), &FlyingHeight, 0, 20);
ImGui::Dummy(ImVec2(0.0f, 3.0f)); 
if(ImGui::SliderFloat(ENC("Buttons X Position"), &sliderX, 0.0f, [[UIScreen mainScreen] bounds].size.width - 40)){
[self updateButtonPositions];
}
if(ImGui::SliderFloat(ENC("Buttons Y Position"), &sliderY, 0.0f, [[UIScreen mainScreen] bounds].size.height - 240)){
[self updateButtonPositions];
}

ImGui::EndTabItem();

}


ImGui::End();


            } 


            ImDrawList* draw_list = ImGui::GetBackgroundDrawList();
            ImVec2 textSize = ImGui::CalcTextSize(ENC("TG @HEHIPA"));
            draw_list->AddText(font, 30.0f, ImVec2(io.DisplaySize.x/2 - textSize.x, io.DisplaySize.y/8), IM_COL32(255, 0, 0, 255), ENC("TG @HEHIPA"));
            startesp();

            ImGui::Render();
            ImDrawData* draw_data = ImGui::GetDrawData();
            ImGui_ImplMetal_RenderDrawData(draw_data, commandBuffer, renderEncoder);
          
            [renderEncoder popDebugGroup];
            [renderEncoder endEncoding];

            [commandBuffer presentDrawable:view.currentDrawable];
        }

        [commandBuffer commit];
}




void saveoff() {
    std::vector<uint64_t*> vars = {
    &NoGrassOffset,
    &ExtendedBuildOffset,
    &SoulOffset,
    &NoShakeOffset,
    &ForceBuildOffset,
    &MttOffset1,
    &MttOffset2,
    &MttOffset3,
    &MttOffset4,
    &MttOffset5,
    &MttOffset6,
    &UnderWaterOffset,
    &NoFallDamageOffset1,
    &NoFallDamageOffset2,
    &NoFallDamageOffset3,
    &FakeOwnerOffset1,
    &FakeOwnerOffset2,
    &FakeOwnerOffset3,
    &FakeOwnerOffset4,
    &NoSpreadOffset1,
    &NoSpreadOffset2,
    &NoRecoilOffset,
    &PictureOffset,
    &LockTimeOffset,
    &NoTreeOffset,
    &NameOffset,
    &NoTextureOffset,
    &BpOff1,
    &BpOff2,
    &BpOff3,
    &BpOff4,
    &BpOff5,
    &BpOff6,
    &BpOff7,
    &BpOff8,
    &BpOff9,
    &BpOff10,
    &BpOff11,
    &BpOff12,
    &BpOff13,
    &BpOff14,
    &BpOff15,
    &BpOff16,
    &BpOff17,
    &BpOff18,
    &BpOff19,
    &BpOff20,
    &BpOff21,
    &BpOff22,
    &BpOff23,
    &BpOff24,
    &BpOff25,
    &BpOff26,
    &BpOff27,
    &BpOff28,
    &BpOff29,
    &BpOff30,
    &BpOff31,
    &BpOff32,
    &BpOff33,
    &BpOff34,
    &BpOff35,
    &BpOff36,
    &BpOff37,
    &BpOff38,
    &BpOff39,
    &BpOff40,
    &BpOff41,
    &BpOff42,
    &BpOff43,
    &BpOff44,
    &BpOff45,
    &BpOff46,
    &BpOff47,
    &BpOff48,
    &BpOff49,
    &BpOff50,
    &BpOff51,
    &BpOff52,
    &BpOff53,
    &BpOff54,
    &BpOff55,
    &BpOff56,
    &BpOff57,
    &BpOff58,
    &BpOff59,
    &BpOff60,
    &BpOff61,
    &BpOff62,
    &BpOff63,
    &BpOff64,
    &BpOff65,
    &BpOff66,
    &BpOff67,
    &BpOff68,
    &BpOff69,
    &BpOff70,
    &BpOff71,
    &BpOff72,
    &BpOff73,
    &BpOff74,
    &BpOff75,
    &BpOff76,
    &BpOff77,
    &BpOff78,
    &BpOff79,
    &BpOff80,
    &BpOff81,
    &BpOff82,
    &BpOff83,
    &BpOff84,
    &BpOff85,
    &BpOff86,
    &BpOff87,
    &BpOff88,
    &BpOff89,
    &BpOff90,
    &BpOff91,
    &BpOff92,
    &BpOff93,
    &BpOff94,
    &InstantExpOffset,
    &AdmEspOffset,
    &NoEnemyAnimOffset1,
    &NoEnemyAnimOffset2,
    &RpgOffOffset,
    &DrinkWaterOffset,
    &SetVelocityOffset,
    &GetVelocityOffset,
    &SetIsKinematicOffset,
    &SetGroundedOffset,
    &SetDetectCollisionsOffset,
    &GetPositionOffset,
    &GetForwardOffset,
    &GetTransformOffset,
    &CameraOffset,
    &W2WPOffset,
    &IsAliveObjectOffset,
    &SetPositionOffset
};

    NSString *filePath = [NSHomeDirectory() stringByAppendingPathComponent:NSENC("Documents/output.txt")];
    NSFileManager *fileManager = [NSFileManager defaultManager];
    
    if ([fileManager fileExistsAtPath:filePath]) {
        [fileManager removeItemAtPath:filePath error:nil];
    }
    
    NSFileHandle *fileHandle = [NSFileHandle fileHandleForWritingAtPath:filePath];
    if (!fileHandle) {
        [[NSFileManager defaultManager] createFileAtPath:filePath contents:nil attributes:nil];
        fileHandle = [NSFileHandle fileHandleForWritingAtPath:filePath];
    }

    for (size_t i = 0; i < vars.size(); i++) {
        NSString *line = [NSString stringWithFormat:NSENC("0x%llx\n"), *vars[i]];
        [fileHandle writeData:[line dataUsingEncoding:NSUTF8StringEncoding]];    

    }
    [fileHandle closeFile];
    
    NSLog(NSENC("Данные записаны в файл: %@"), filePath);
}


void OpenURL(NSString *urlString) {
    NSURL *url = [NSURL URLWithString:urlString];
    if ([[UIApplication sharedApplication] canOpenURL:url]) {
        [[UIApplication sharedApplication] openURL:url options:@{} completionHandler:^(BOOL success) {
            if (success) {
                NSLog(NSENC("Ссылка открыта успешно."));
            } else {
                NSLog(NSENC("Не удалось открыть ссылку."));
            }
        }];
    } else {
        NSLog(NSENC("Невозможно открыть ссылку: %@"), urlString);
    }
}


- (void)Flying{
    UIWindow *Window = [[[UIApplication sharedApplication] delegate] window];
    UP = [[UIButton alloc] initWithFrame:CGRectMake(sliderX, sliderY, 40, 40)];
    UP.layer.cornerRadius = 10.0;
    [UP setTitle:NSENC("UP") forState:UIControlStateNormal];
    [UP setTitleColor:[UIColor whiteColor] forState:UIControlStateNormal];
    UP.backgroundColor = [UIColor colorWithRed:34/255.0 green:181/255.0 blue:115/250.0 alpha:1];
    UP.layer.borderWidth = 0;
    [UP.titleLabel setFont:[UIFont systemFontOfSize:17]];
    [UP addTarget:self action:@selector(sheng) forControlEvents:UIControlEventTouchUpInside];
    [Window addSubview:UP];

    LOCK = [[UIButton alloc] initWithFrame:CGRectMake(sliderX, sliderY + 45, 40, 40)];
    LOCK.layer.cornerRadius = 10.0;//2.0是圆角的弧度，根据需求自己更改
    [LOCK setTitle:NSENC("LOCK") forState:UIControlStateNormal];
    [LOCK setTitleColor:[UIColor whiteColor] forState:UIControlStateNormal];//p1颜色
    LOCK.backgroundColor = [UIColor colorWithRed:255/255.0 green:0/255.0 blue:0/250.0 alpha:1];
    LOCK.layer.borderWidth = 0;//边框大小
    [LOCK.titleLabel setFont:[UIFont systemFontOfSize:10]];//字体大小
    [LOCK addTarget:self action:@selector(suo) forControlEvents:UIControlEventTouchUpInside];
    [Window addSubview:LOCK];
    
    DOWN = [[UIButton alloc] initWithFrame:CGRectMake(sliderX, sliderY + 90, 40, 40)];
    DOWN.layer.cornerRadius = 10.0;//2.0是圆角的弧度，根据需求自己更改
    [DOWN setTitle:NSENC("DOWN") forState:UIControlStateNormal];
    [DOWN setTitleColor:[UIColor whiteColor] forState:UIControlStateNormal];//p1颜色
    DOWN.backgroundColor = [UIColor colorWithRed:34/255.0 green:181/255.0 blue:115/250.0 alpha:1];
    DOWN.layer.borderWidth = 0;//边框大小
    [DOWN.titleLabel setFont:[UIFont systemFontOfSize:10]];//字体大小
    [DOWN addTarget:self action:@selector(jiang) forControlEvents:UIControlEventTouchUpInside];
    [Window addSubview:DOWN];

    SOUL = [[UIButton alloc] initWithFrame:CGRectMake(sliderX, sliderY + 135, 40, 40)];
    SOUL.layer.cornerRadius = 10.0;//2.0是圆角的弧度，根据需求自己更改
    [SOUL setTitle:NSENC("SOUL") forState:UIControlStateNormal];
    [SOUL setTitleColor:[UIColor whiteColor] forState:UIControlStateNormal];//p1颜色
    SOUL.backgroundColor = [UIColor colorWithRed:255/255.0 green:0/255.0 blue:0/250.0 alpha:1];
    SOUL.layer.borderWidth = 0;//边框大小
    [SOUL.titleLabel setFont:[UIFont systemFontOfSize:10]];//字体大小
    [SOUL addTarget:self action:@selector(soulb) forControlEvents:UIControlEventTouchUpInside];
    [Window addSubview:SOUL];

    NOCLIP = [[UIButton alloc] initWithFrame:CGRectMake(sliderX, sliderY + 180, 40, 40)];
    NOCLIP.layer.cornerRadius = 10.0;//2.0是圆角的弧度，根据需求自己更改
    [NOCLIP setTitle:NSENC("NOCLIP") forState:UIControlStateNormal];
    [NOCLIP setTitleColor:[UIColor whiteColor] forState:UIControlStateNormal];//p1颜色
    NOCLIP.backgroundColor = [UIColor colorWithRed:255/255.0 green:0/255.0 blue:0/250.0 alpha:1];
    NOCLIP.layer.borderWidth = 0;//边框大小
    [NOCLIP.titleLabel setFont:[UIFont systemFontOfSize:10]];//字体大小
    [NOCLIP addTarget:self action:@selector(noclipb) forControlEvents:UIControlEventTouchUpInside];
    [Window addSubview:NOCLIP];

}

- (void)updateButtonPositions {
    UP.frame = CGRectMake(sliderX, sliderY, 40, 40);
    LOCK.frame = CGRectMake(sliderX, sliderY + 45, 40, 40);
    DOWN.frame = CGRectMake(sliderX, sliderY + 90, 40, 40);
    SOUL.frame = CGRectMake(sliderX, sliderY + 135, 40, 40);
    NOCLIP.frame = CGRectMake(sliderX, sliderY + 180, 40, 40);
}

- (void)updateButtonColors {
    UP.backgroundColor = [UIColor colorWithRed:34/255.0 green:181/255.0 blue:115/250.0 alpha:1];
    DOWN.backgroundColor = [UIColor colorWithRed:34/255.0 green:181/255.0 blue:115/250.0 alpha:1];
    if(soul){
    SOUL.backgroundColor = [UIColor colorWithRed:34/255.0 green:181/255.0 blue:115/250.0 alpha:1];
    }else{
    SOUL.backgroundColor = [UIColor colorWithRed:255/255.0 green:0/255.0 blue:0/250.0 alpha:1];
    }
    
    if(noclip){
    NOCLIP.backgroundColor = [UIColor colorWithRed:34/255.0 green:181/255.0 blue:115/250.0 alpha:1];
    }else{
    NOCLIP.backgroundColor = [UIColor colorWithRed:255/255.0 green:0/255.0 blue:0/250.0 alpha:1];
    }
    
    if(Plock){
    LOCK.backgroundColor = [UIColor colorWithRed:34/255.0 green:181/255.0 blue:115/250.0 alpha:1];
    }else{
    LOCK.backgroundColor = [UIColor colorWithRed:255/255.0 green:0/255.0 blue:0/250.0 alpha:1];
    }

}

- (void)sheng{
    [self modifyLocalPlayerPosX:0 y:1 z:0];
}
- (void)jiang{
    [self modifyLocalPlayerPosX:0 y:-1 z:0];
}
- (void)suo{
    Plock =! Plock;

    if(isJb == 1){
        if(Plock){
            vm_unity32(GetVelocityOffset, strtoul(ENCRYPT("0xC0035FD6"), nullptr, 0));
        }else{
            vm_unity32(GetVelocityOffset, strtoul(ENCRYPT("0xFFC300D1"), nullptr, 0));
        }

    }else{
        if(Plock){
            ActiveCodePatch(UnityFramework, GetVelocityOffset, "C0035FD6");
        }else{
            DeactiveCodePatch(UnityFramework, GetVelocityOffset, "C0035FD6");
        }
    }


    [self updateButtonColors];
}
- (void)soulb{
    soul =! soul;
    offsetFunc();
    [self updateButtonColors];
}
- (void)noclipb{
   noclip =! noclip;
   if(noclip){
      HexIpa->set_detectCollisions(me->rigid, false);
//vm_unity32(ENCRYPTOFFSET("0x12FDEB0"), strtoul(ENCRYPTHEX("0xC0035FD6"), nullptr, 0));
   }else{
      HexIpa->set_detectCollisions(me->rigid, true);
   }
   [self updateButtonColors];
}

- (void)modifyLocalPlayerPosX:(float)x y:(float)y z:(float)z
{
    void* playerTransform = me->trans;

    Vector3 position = me->pos;

    position.x += x * Xhit;
    position.y += y * FlyingHeight;
    position.z += z * MAX(FlyingHeight, 6);
    
    HexIpa->set_position(playerTransform, position);
}


- (void)mtkView:(MTKView*)view drawableSizeWillChange:(CGSize)size
{
    
}


@end

