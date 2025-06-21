#include <sys/mman.h>
bool isMincore(uintptr_t address, size_t size) {
    size_t pageSize = getpagesize();
    uintptr_t alignedAddress = address & ~(pageSize - 1);

    char vec;
    if (mincore((void *)alignedAddress, size, &vec) == 0) {
        return vec & 1; 
    }
    return false;
}

struct EnemyInfo {
    Vector3 pos;
    int Hp;
    int MaxHp;
    std::string Name;
};

struct Bounds{
    Vector3 center;
    Vector3 extents;
    Vector3 min()
    {
        return center - extents;
    }
    Vector3 max()
    {
        return center + extents;
    }
};

struct enemy_t{
    void *ptr;
    void *trans;
    void *playerinfo;
    void *mesh;
    Vector3 pos;
    ImVec2 w2spos;    
    ImVec2 w2stop;    
    Bounds boundz;
    int Hp;
    int MaxHp;
    std::string Name;
    
};
enemy_t *enemy;


struct Mine_t{
    void *ptr;
    void *trans;
    Vector3 pos;
    ImVec2 w2spos;    
    std::string Name;    
};
Mine_t *Mine;

struct me_t{
    void *ptr;
    void *trans;
    void *rigid; 
    Vector3 pos;
    void *cam;
};
me_t *me;

struct ESP {
    bool Draw = false;
    bool Line = false;
    bool Hp = false;
    bool Distance = false;
    bool Bones = false;
    bool Name = false;
    bool ZBox = false;
    bool Box3D = false;
}ESP;

struct MonsterESP {
    bool Draw = false;
    bool Line = false;
    bool Hp = false;
    bool Distance = false;
    bool Name = false;
}MonsterESP;

struct MineESP {
    bool Draw = false;

}MineESP;

static inline ImVec2  operator*(const ImVec2& lhs, const float rhs) { return ImVec2(lhs.x * rhs, lhs.y * rhs); }
static inline ImVec2  operator/(const ImVec2& lhs, const float rhs) { return ImVec2(lhs.x / rhs, lhs.y / rhs); }
static inline ImVec2  operator+(const ImVec2& lhs, const float rhs) { return ImVec2(lhs.x + rhs, lhs.y + rhs); }
static inline ImVec2  operator+(const ImVec2& lhs, const ImVec2& rhs) { return ImVec2(lhs.x + rhs.x, lhs.y + rhs.y); }
static inline ImVec2  operator-(const ImVec2& lhs, const ImVec2& rhs) { return ImVec2(lhs.x - rhs.x, lhs.y - rhs.y); }
static inline ImVec2  operator-(const ImVec2& lhs, const float rhs) { return ImVec2(lhs.x - rhs, lhs.y - rhs); }
static inline ImVec2  operator*(const ImVec2& lhs, const ImVec2& rhs) { return ImVec2(lhs.x * rhs.x, lhs.y * rhs.y); }
static inline ImVec2  operator/(const ImVec2& lhs, const ImVec2& rhs) { return ImVec2(lhs.x / rhs.x, lhs.y / rhs.y); }
static inline ImVec2& operator*=(ImVec2& lhs, const float rhs) { lhs.x *= rhs; lhs.y *= rhs; return lhs; }
static inline ImVec2& operator/=(ImVec2& lhs, const float rhs) { lhs.x /= rhs; lhs.y /= rhs; return lhs; }
static inline ImVec2& operator+=(ImVec2& lhs, const ImVec2& rhs) { lhs.x += rhs.x; lhs.y += rhs.y; return lhs; }
static inline ImVec2& operator-=(ImVec2& lhs, const ImVec2& rhs) { lhs.x -= rhs.x; lhs.y -= rhs.y; return lhs; }
static inline ImVec2& operator*=(ImVec2& lhs, const ImVec2& rhs) { lhs.x *= rhs.x; lhs.y *= rhs.y; return lhs; }
static inline ImVec2& operator/=(ImVec2& lhs, const ImVec2& rhs) { lhs.x /= rhs.x; lhs.y /= rhs.y; return lhs; }
static inline ImVec4  operator+(const ImVec4& lhs, const ImVec4& rhs) { return ImVec4(lhs.x + rhs.x, lhs.y + rhs.y, lhs.z + rhs.z, lhs.w + rhs.w); }
static inline ImVec4  operator-(const ImVec4& lhs, const ImVec4& rhs) { return ImVec4(lhs.x - rhs.x, lhs.y - rhs.y, lhs.z - rhs.z, lhs.w - rhs.w); }
static inline ImVec4  operator*(const ImVec4& lhs, const ImVec4& rhs) { return ImVec4(lhs.x * rhs.x, lhs.y * rhs.y, lhs.z * rhs.z, lhs.w * rhs.w); }

inline ImVec2 flooring(ImVec2 vec) {
    return { static_cast<float>(vec.x), (float)int(vec.y) };
}

inline ImVec2 flooring(float x, float y) {
    return { (float)int(x), (float)int(y) };
}

inline ImVec2 flooring(int x, int y) {
    return { (float)x, (float)y };
}