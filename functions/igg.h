#include "JRMemory.framework/Headers/MemScan.h"

void iggFunc(){
                   
if (instantrpg) {
JRMemoryEngine engine = JRMemoryEngine(mach_task_self());
AddrRange range = (AddrRange){0x100000000,0x200000000};
float search1 = 3;
engine.JRScanMemory(range, &search1, JR_Search_Type_Float);
float search2 = 10;
engine.JRNearBySearch(0x100, &search2, JR_Search_Type_Float);
float search3 = 4;
engine.JRNearBySearch(0x100, &search3, JR_Search_Type_Float);
float search4 = 40;
engine.JRNearBySearch(0x100, &search4, JR_Search_Type_Float);
float search5 = 4;
engine.JRNearBySearch(0x100, &search5, JR_Search_Type_Float);
float search6 = 2.799999952316284;
engine.JRNearBySearch(0x100, &search6, JR_Search_Type_Float);
float search7 = 40;
engine.JRScanMemory(range, &search7, JR_Search_Type_Float);
vector<void*>results = engine.getAllResults();
float modify = 99999;
for(int i =0;i<results.size();i++){
    engine.JRWriteMemory((unsigned long long)(results[i]),&modify,JR_Search_Type_Float);
  }
}



if (firerate) {
dispatch_queue_t queue = dispatch_queue_create(ENC("net.bujige.testQueue"), DISPATCH_QUEUE_SERIAL);
dispatch_async(queue, ^{
JRMemoryEngine engine = JRMemoryEngine(mach_task_self());
AddrRange range = (AddrRange){0x00000000,0x160000000};
uint32_t search = 1119748096;
engine.JRScanMemory(range, &search, JR_Search_Type_UInt);
vector<void*>results = engine.getAllResults();
uint32_t modify = -1082130432;
for(int i = 0; i < results.size(); i++){
    engine.JRWriteMemory((unsigned long long)(results[i]),&modify,JR_Search_Type_UInt);
   }
  });
}


if (x8scope) {
dispatch_queue_t queue = dispatch_queue_create(ENC("net.bujige.testQueue"), DISPATCH_QUEUE_SERIAL);
dispatch_async(queue, ^{
JRMemoryEngine engine = JRMemoryEngine(mach_task_self());
AddrRange range = (AddrRange){0x100000000,0x200000000};
float search = 48;
engine.JRScanMemory(range, &search, JR_Search_Type_Float);
float Nearsearch = 1.401298e-45;
engine.JRNearBySearch(0x50,&Nearsearch,JR_Search_Type_Float);
float search1 = 48;
engine.JRScanMemory(range, &search1, JR_Search_Type_Float);
vector<void*>results = engine.getAllResults();
float modify = 10;
for(int i =0;i<results.size();i++){
    engine.JRWriteMemory((unsigned long long)(results[i]),&modify,JR_Search_Type_Float);
    }
  });
}


if (magic06) {
dispatch_queue_t queue = dispatch_queue_create(ENC("net.bujige.testQueue"), DISPATCH_QUEUE_SERIAL);
dispatch_async(queue, ^{
JRMemoryEngine engine = JRMemoryEngine(mach_task_self());
AddrRange range = (AddrRange){0x100000000,0x300000000};
float search = 0.16;
engine.JRScanMemory(range, &search, JR_Search_Type_Float);
vector<void*>results = engine.getAllResults();
float modify = 0.6;
for(int i = 0;i<results.size();i++){
    engine.JRWriteMemory((unsigned long long)(results[i]),&modify,JR_Search_Type_Float);
}
  });
}

if (magic12) {
dispatch_queue_t queue = dispatch_queue_create(ENC("net.bujige.testQueue"), DISPATCH_QUEUE_SERIAL);
dispatch_async(queue, ^{
JRMemoryEngine engine = JRMemoryEngine(mach_task_self());
AddrRange range = (AddrRange){0x100000000,0x300000000};
float search = 0.16;
engine.JRScanMemory(range, &search, JR_Search_Type_Float);
vector<void*>results = engine.getAllResults();
float modify = 1.2;
for(int i = 0;i<results.size();i++){
    engine.JRWriteMemory((unsigned long long)(results[i]),&modify,JR_Search_Type_Float);}
  });
}

if (magic120) {
dispatch_queue_t queue = dispatch_queue_create(ENC("net.bujige.testQueue"), DISPATCH_QUEUE_SERIAL);
dispatch_async(queue, ^{
JRMemoryEngine engine = JRMemoryEngine(mach_task_self());
AddrRange range = (AddrRange){0x100000000,0x300000000};
float search = 0.16;
engine.JRScanMemory(range, &search, JR_Search_Type_Float);
vector<void*>results = engine.getAllResults();
float modify = 12;
for(int i = 0;i<results.size();i++){
    engine.JRWriteMemory((unsigned long long)(results[i]),&modify,JR_Search_Type_Float);}
  });
}


if (magicbullet) {
dispatch_queue_t queue = dispatch_queue_create(ENC("net.bujige.testQueue"), DISPATCH_QUEUE_SERIAL);
dispatch_async(queue, ^{
JRMemoryEngine engine = JRMemoryEngine(mach_task_self());
AddrRange range = (AddrRange){0x100000000,0x300000000};
uint64_t search = 4553319368127403786;
engine.JRScanMemory(range, &search, JR_Search_Type_SLong);
vector<void*>results = engine.getAllResults();
uint64_t modify = 4553319368154415104;
for(int i =0;i<results.size();i++){
    engine.JRWriteMemory((unsigned long long)(results[i]),&modify,JR_Search_Type_SLong);
   }
 });
}


if (knife06) {
dispatch_queue_t queue = dispatch_queue_create(ENC("net.bujige.testQueue"), DISPATCH_QUEUE_SERIAL);
dispatch_async(queue, ^{
JRMemoryEngine engine = JRMemoryEngine(mach_task_self());
AddrRange range = (AddrRange){0x100000000,0x300000000};
float search = 0.11;
engine.JRScanMemory(range, &search, JR_Search_Type_Float);
vector<void*>results = engine.getAllResults();
float modify = 0.6;
for(int i =0;i<results.size();i++){
    engine.JRWriteMemory((unsigned long long)(results[i]),&modify,JR_Search_Type_Float);
   }
 });
}

if (knife12) {
dispatch_queue_t queue = dispatch_queue_create(ENC("net.bujige.testQueue"), DISPATCH_QUEUE_SERIAL);
dispatch_async(queue, ^{
JRMemoryEngine engine = JRMemoryEngine(mach_task_self());
AddrRange range = (AddrRange){0x100000000,0x300000000};
float search = 0.11;
engine.JRScanMemory(range, &search, JR_Search_Type_Float);
vector<void*>results = engine.getAllResults();
float modify = 1.2;
for(int i =0;i<results.size();i++){
    engine.JRWriteMemory((unsigned long long)(results[i]),&modify,JR_Search_Type_Float);
       }
   });
}

if (knife120) {
dispatch_queue_t queue = dispatch_queue_create(ENC("net.bujige.testQueue"), DISPATCH_QUEUE_SERIAL);
dispatch_async(queue, ^{
JRMemoryEngine engine = JRMemoryEngine(mach_task_self());
AddrRange range = (AddrRange){0x100000000,0x300000000};
float search = 0.11;
engine.JRScanMemory(range, &search, JR_Search_Type_Float);
vector<void*>results = engine.getAllResults();
float modify = 12;
for(int i =0;i<results.size();i++){
    engine.JRWriteMemory((unsigned long long)(results[i]),&modify,JR_Search_Type_Float);
       }
   });
}

if (magicknife) {
dispatch_queue_t queue = dispatch_queue_create(ENC("net.bujige.testQueue"), DISPATCH_QUEUE_SERIAL);
dispatch_async(queue, ^{
JRMemoryEngine engine = JRMemoryEngine(mach_task_self());
AddrRange range = (AddrRange){0x100000000,0x300000000};
float search = 0.11;
engine.JRScanMemory(range, &search, JR_Search_Type_Float);
vector<void*>results = engine.getAllResults();
float modify = 2;
for(int i =0;i<results.size();i++){
    engine.JRWriteMemory((unsigned long long)(results[i]),&modify,JR_Search_Type_Float);
         }
    });
}

if (waterbuild) {
dispatch_queue_t queue = dispatch_queue_create(ENC("net.bujige.testQueue"), DISPATCH_QUEUE_SERIAL);
dispatch_async(queue, ^{
JRMemoryEngine engine_dift = JRMemoryEngine(mach_task_self());
JRMemoryEngine engine = JRMemoryEngine(mach_task_self());
AddrRange range = (AddrRange){0x100000000,0x290000000};
uint64_t search = 1125899906842625;
engine.JRScanMemory(range, &search, JR_Search_Type_SLong);
uint64_t Nearsearch = 4503600701112320;
engine.JRNearBySearch(0x10,&Nearsearch,JR_Search_Type_SLong);
uint64_t search1 = 1125899906842625;
engine.JRScanMemory(range, &search1, JR_Search_Type_SLong);
vector<void*>results = engine.getAllResults();
uint64_t modify = 206403243343873;
for(int i =0;i<results.size();i++){
    engine.JRWriteMemory((unsigned long long)(results[i]),&modify,JR_Search_Type_SLong);
       }
   });
} else {
JRMemoryEngine engine = JRMemoryEngine(mach_task_self());
AddrRange range = (AddrRange){0x100000000,0x290000000};
uint64_t search = 206403243343873;
engine.JRScanMemory(range, &search, JR_Search_Type_SLong);
uint64_t Nearsearch = 4503600701112320;
engine.JRNearBySearch(0x10,&Nearsearch,JR_Search_Type_SLong);
uint64_t search1 = 206403243343873;
engine.JRScanMemory(range, &search1, JR_Search_Type_SLong);
vector<void*>results = engine.getAllResults();
uint64_t modify = 1125899906842625;
for(int i =0;i<results.size();i++){
    engine.JRWriteMemory((unsigned long long)(results[i]),&modify,JR_Search_Type_SLong);
   }
}

if (timechange) {
dispatch_queue_t queue = dispatch_queue_create(ENC("net.bujige.testQueue"), DISPATCH_QUEUE_SERIAL);
dispatch_async(queue, ^{
JRMemoryEngine engine = JRMemoryEngine(mach_task_self());
AddrRange range = (AddrRange){0x100000000,0x200000000};
float search = 0.0067;
engine.JRScanMemory(range, &search, JR_Search_Type_Float);
float search1 = 9.21942e-41;
engine.JRNearBySearch(0x60,&search1,JR_Search_Type_Float);
float search2 = 9.21942e-41;
engine.JRScanMemory(range, &search2,JR_Search_Type_Float);
vector<void*>results = engine.getAllResults();
float modify = -999;
for(int i =0;i<results.size();i++){
    engine.JRWriteMemory((unsigned long long)(results[i]),&modify,JR_Search_Type_Float);
      }
   });
}

if(fastbike){
dispatch_queue_t queue = dispatch_queue_create(ENC("net.bujige.testQueue"), DISPATCH_QUEUE_SERIAL);
dispatch_async(queue, ^{
JRMemoryEngine engine = JRMemoryEngine(mach_task_self());
AddrRange range = (AddrRange){0x100000000,0x2000000000};
float search = 30;
engine.JRScanMemory(range, &search, JR_Search_Type_Float);
float search1 = 45;
engine.JRNearBySearch(0x100,&search1,JR_Search_Type_Float);
float search2 = 30;
engine.JRScanMemory(range, &search2,JR_Search_Type_Float);
vector<void*>results = engine.getAllResults();
float modify = 75;
for(int i =0;i<results.size();i++){
    engine.JRWriteMemory((unsigned long long)(results[i]),&modify,JR_Search_Type_Float);
      }
   });
}

if (highfov) {
dispatch_queue_t queue = dispatch_queue_create(ENC("net.bujige.testQueue"), DISPATCH_QUEUE_SERIAL);
dispatch_async(queue, ^{
JRMemoryEngine engine_dsrc = JRMemoryEngine(mach_task_self());
AddrRange range = (AddrRange){0x100000000,0x270000000};
float search = 1.70000004768;
engine_dsrc.JRScanMemory(range, &search, JR_Search_Type_Float);
vector<void*>results = engine_dsrc.getAllResults();
float modify = 5;
for(int i =0;i<results.size();i++){
    engine_dsrc.JRWriteMemory((unsigned long long)(results[i]),&modify,JR_Search_Type_Float);
      }
   });
}

if (whitebody) {
JRMemoryEngine engine = JRMemoryEngine(mach_task_self());
AddrRange range = (AddrRange){0x00000000,0x180000000};
int32_t search = 75;
engine.JRScanMemory(range, &search, JR_Search_Type_SInt);
int32_t search1 = 58;
engine.JRNearBySearch(0x100, &search1, JR_Search_Type_SInt);
float search2 = .75;
engine.JRNearBySearch(0x100, &search2, JR_Search_Type_Float);
float search3 = .75;
engine.JRScanMemory(range, &search3, JR_Search_Type_Float);
vector<void*>results = engine.getAllResults();
float modify = 999;
for(int i =0;i<results.size();i++){
    engine.JRWriteMemory((unsigned long long)(results[i]),&modify,JR_Search_Type_Float);
   }
}

if (blackbody) {
JRMemoryEngine engine = JRMemoryEngine(mach_task_self());
AddrRange range = (AddrRange){0x00000000,0x180000000};
int32_t search = 75;
engine.JRScanMemory(range, &search, JR_Search_Type_SInt);
int32_t search1 = 58;
engine.JRNearBySearch(0x100, &search1, JR_Search_Type_SInt);
float search2 = .75;
engine.JRNearBySearch(0x100, &search2, JR_Search_Type_Float);
float search3 = .75;
engine.JRScanMemory(range, &search3, JR_Search_Type_Float);
vector<void*>results = engine.getAllResults();
float modify = -999;
for(int i =0;i<results.size();i++){
    engine.JRWriteMemory((unsigned long long)(results[i]),&modify,JR_Search_Type_Float);
   }
} 


}