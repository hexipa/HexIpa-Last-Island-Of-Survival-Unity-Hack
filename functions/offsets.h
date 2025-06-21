#import "functions/inline-hook/static-inline.h"
#import "variables.h"
#pragma GCC diagnostic ignored "-Wwritable-strings"

static char *UnityFramework = "Frameworks/UnityFramework.framework/UnityFramework";


void offsetFunc(){
            

if(isJb == 0){

if(exbuild){
        if(exbuild_active == NO){
ActiveCodePatch(UnityFramework, ExtendedBuildOffset, "C0035FD6");
            }
        exbuild_active = YES;
    }
    else{
        if(exbuild_active == YES){
DeactiveCodePatch(UnityFramework, ExtendedBuildOffset, "C0035FD6");
            }
        exbuild_active = NO;
    }


if(soul == true){
        if(soul_active == NO){
ActiveCodePatch(UnityFramework, SoulOffset, "C0035FD6");       
            }
        soul_active = YES;
    }
    else{
        if(soul_active == YES){
DeactiveCodePatch(UnityFramework, SoulOffset, "C0035FD6"); 
            }
        soul_active = NO;
    }

if(noshake){
        if(noshake_active == NO){
ActiveCodePatch(UnityFramework, NoShakeOffset, "C0035FD6");       
            }
        noshake_active = YES;
    }
    else{
        if(noshake_active == YES){
DeactiveCodePatch(UnityFramework, NoShakeOffset, "C0035FD6");       
            }
        noshake_active = NO;
    }

if(forcebuild){
        if(forcebuild_active == NO){
ActiveCodePatch(UnityFramework, ForceBuildOffset, "C0035FD6");       
            }
        forcebuild_active = YES;
    }
    else{
        if(forcebuild_active == YES){
DeactiveCodePatch(UnityFramework, ForceBuildOffset, "C0035FD6");       
            }
        forcebuild_active = NO;
    }


if(mtt){
        if(mtt_active == NO){
ActiveCodePatch(UnityFramework, MttOffset1, "C0035FD6");       
ActiveCodePatch(UnityFramework, MttOffset2, "C0035FD6");       
ActiveCodePatch(UnityFramework, MttOffset3, "C0035FD6");       
ActiveCodePatch(UnityFramework, MttOffset4, "C0035FD6");       
ActiveCodePatch(UnityFramework, MttOffset5, "C0035FD6");       
ActiveCodePatch(UnityFramework, MttOffset6, "C0035FD6");       
            }
        mtt_active = YES;
    }
    else{
        if(mtt_active == YES){
DeactiveCodePatch(UnityFramework, MttOffset1, "C0035FD6");       
DeactiveCodePatch(UnityFramework, MttOffset2, "C0035FD6");       
DeactiveCodePatch(UnityFramework, MttOffset3, "C0035FD6");       
DeactiveCodePatch(UnityFramework, MttOffset4, "C0035FD6");       
DeactiveCodePatch(UnityFramework, MttOffset5, "C0035FD6");       
DeactiveCodePatch(UnityFramework, MttOffset6, "C0035FD6");                  
            }
        mtt_active = NO;
    }

if(underwater){
        if(underwater_active == NO){
ActiveCodePatch(UnityFramework, UnderWaterOffset, "C0035FD6");       
            }
        underwater_active = YES;
    }
    else{
        if(underwater_active == YES){
DeactiveCodePatch(UnityFramework, UnderWaterOffset, "C0035FD6");       
            }
        underwater_active = NO;
    }

if(nofalldamage){
        if(nofalldamage_active == NO){
ActiveCodePatch(UnityFramework, NoFallDamageOffset1, "C0035FD6");       
ActiveCodePatch(UnityFramework, NoFallDamageOffset2, "C0035FD6");       
ActiveCodePatch(UnityFramework, NoFallDamageOffset3, "C0035FD6");       
            }
        nofalldamage_active = YES;
    }
    else{
        if(nofalldamage_active == YES){
DeactiveCodePatch(UnityFramework, NoFallDamageOffset1, "C0035FD6");       
DeactiveCodePatch(UnityFramework, NoFallDamageOffset2, "C0035FD6");       
DeactiveCodePatch(UnityFramework, NoFallDamageOffset3, "C0035FD6");       
            }
        nofalldamage_active = NO;
    }

if(fakeowner){
        if(fakeowner_active == NO){
ActiveCodePatch(UnityFramework, FakeOwnerOffset1, "200080D2C0035FD6");       
ActiveCodePatch(UnityFramework, FakeOwnerOffset2, "200080D2C0035FD6");       
ActiveCodePatch(UnityFramework, FakeOwnerOffset3, "200080D2C0035FD6");       
ActiveCodePatch(UnityFramework, FakeOwnerOffset4, "200080D2C0035FD6");            
            }
        fakeowner_active = YES;
    }
    else{
        if(fakeowner_active == YES){
DeactiveCodePatch(UnityFramework, FakeOwnerOffset1, "200080D2C0035FD6");       
DeactiveCodePatch(UnityFramework, FakeOwnerOffset2, "200080D2C0035FD6");       
DeactiveCodePatch(UnityFramework, FakeOwnerOffset3, "200080D2C0035FD6");       
DeactiveCodePatch(UnityFramework, FakeOwnerOffset4, "200080D2C0035FD6");                
            }
        fakeowner_active = NO;
    }

if(nospread){
        if(nospread_active == NO){
ActiveCodePatch(UnityFramework, NoSpreadOffset1, "C0035FD6");       
ActiveCodePatch(UnityFramework, NoSpreadOffset2, "C0035FD6");       
            }
        nospread_active = YES;
    }
    else{
        if(nospread_active == YES){
DeactiveCodePatch(UnityFramework, NoSpreadOffset1, "C0035FD6");       
DeactiveCodePatch(UnityFramework, NoSpreadOffset2, "C0035FD6");       
            }
        nospread_active = NO;
    }

if(norecoil){
        if(norecoil_active == NO){
ActiveCodePatch(UnityFramework, NoRecoilOffset, "C0035FD6");       
            }
        norecoil_active = YES;
    }
    else{
        if(norecoil_active == YES){
DeactiveCodePatch(UnityFramework, NoRecoilOffset, "C0035FD6");       
            }
        norecoil_active = NO;
    }

if(picture){
        if(picture_active == NO){
ActiveCodePatch(UnityFramework, PictureOffset, "200080D2C0035FD6");       
            }
        picture_active = YES;
    }
    else{
        if(picture_active == YES){
DeactiveCodePatch(UnityFramework, PictureOffset, "200080D2C0035FD6");       
            }
        picture_active = NO;
    }

if(locktime){
        if(locktime_active == NO){
ActiveCodePatch(UnityFramework, LockTimeOffset, "C0035FD6");       
            }
        locktime_active = YES;
    }
    else{
        if(locktime_active == YES){
DeactiveCodePatch(UnityFramework, LockTimeOffset, "C0035FD6");       
            }
        locktime_active = NO;
    }

if(nograss){
        if(nograss_active == NO){
ActiveCodePatch(UnityFramework, NoGrassOffset, "C0035FD6");       
            }
        nograss_active = YES;
    }
    else{
        if(nograss_active == YES){
DeactiveCodePatch(UnityFramework, NoGrassOffset, "C0035FD6");       
            }
        nograss_active = NO;
    }

if(notree){
        if(notree_active == NO){
ActiveCodePatch(UnityFramework, NoTreeOffset, "C0035FD6");       
            }
        notree_active = YES;
    }
    else{
        if(notree_active == YES){
DeactiveCodePatch(UnityFramework, NoTreeOffset, "C0035FD6");       
            }
        notree_active = NO;
    }



if(name){
        if(name_active == NO){
ActiveCodePatch(UnityFramework, NameOffset, "200080D2C0035FD6");       
            }
        name_active = YES;
    }
    else{
        if(name_active == YES){
DeactiveCodePatch(UnityFramework, NameOffset, "200080D2C0035FD6");       
            }
        name_active = NO;
    }



if(notexture){
    if(notexture_active == NO){
ActiveCodePatch(UnityFramework, NoTextureOffset, "C0035FD6");       
        }
    notexture_active = YES;
}
else{
    if(notexture_active == YES){
DeactiveCodePatch(UnityFramework, NoTextureOffset, "C0035FD6");       
        }
    notexture_active = NO;
}


if(instantexp){
        if(instantexp_active == NO){
ActiveCodePatch(UnityFramework, InstantExpOffset, "C0035FD6");
            }
        instantexp_active = YES;
    }
    else{
        if(instantexp_active == YES){
DeactiveCodePatch(UnityFramework, InstantExpOffset, "C0035FD6");
            }
        instantexp_active = NO;
    }

if(admesp){
        if(admesp_active == NO){
ActiveCodePatch(UnityFramework, AdmEspOffset, "200080D2C0035FD6");
            }
        admesp_active = YES;
    }
    else{
        if(admesp_active == YES){
DeactiveCodePatch(UnityFramework, AdmEspOffset, "200080D2C0035FD6");
            }
        admesp_active = NO;
    }

if(noenemyanim){
        if(noenemyanim_active == NO){
ActiveCodePatch(UnityFramework, NoEnemyAnimOffset1, "C0035FD6");
ActiveCodePatch(UnityFramework, NoEnemyAnimOffset2, "C0035FD6");
            }
        noenemyanim_active = YES;
    }
    else{
        if(noenemyanim_active == YES){
DeactiveCodePatch(UnityFramework, NoEnemyAnimOffset1, "C0035FD6");
DeactiveCodePatch(UnityFramework, NoEnemyAnimOffset2, "C0035FD6");
            }
        noenemyanim_active = NO;
    }


if(traceroff){
        if(traceroff_active == NO){

            }
        traceroff_active = YES;
    }
    else{
        if(traceroff_active == YES){

            }
        traceroff_active = NO;
    }

if(rpgoff){
        if(rpgoff_active == NO){
ActiveCodePatch(UnityFramework, RpgOffOffset, "C0035FD6");
            }
        rpgoff_active = YES;
    }
    else{
        if(rpgoff_active == YES){
DeactiveCodePatch(UnityFramework, RpgOffOffset, "C0035FD6");
            }
        rpgoff_active = NO;
    }

if(drinkwater){
        if(drinkwater_active == NO){
ActiveCodePatch(UnityFramework, DrinkWaterOffset, "C0035FD6");
            }
        drinkwater_active = YES;
    }
    else{
        if(drinkwater_active == YES){
DeactiveCodePatch(UnityFramework, DrinkWaterOffset, "C0035FD6");
            }
        drinkwater_active = NO;
    }

if(gm){

}else{

}


}else{

if(exbuild){
        if(exbuild_active == NO){
            //vm_unity32(ENCRYPTOFFSET("0xEC7810"), strtoul(ENCRYPTHEX("0xC0035FD6"), nullptr, 0));
            //vm_unity32(ENCRYPTOFFSET("0x108AA3C"), strtoul(ENCRYPTHEX("0xC0035FD6"), nullptr, 0));
            vm_unity32(ExtendedBuildOffset, strtoul(ENCRYPT("0xC0035FD6"), nullptr, 0));

            }
        exbuild_active = YES;
    }
    else{
        if(exbuild_active == YES){
            vm_unity32(ExtendedBuildOffset, strtoul(ENCRYPT("0xFFC302D1"), nullptr, 0));
            }
        exbuild_active = NO;
    }


if(soul){
        if(soul_active == NO){
            
            vm_unity32(SoulOffset, strtoul(ENCRYPT("0xC0035FD6"), nullptr, 0));

            }
        soul_active = YES;
    }
    else{
        if(soul_active == YES){
            vm_unity32(SoulOffset, strtoul(ENCRYPT("0xFF0303D1"), nullptr, 0));
            }
        soul_active = NO;
    }

if(noshake){
        if(noshake_active == NO){
            vm_unity32(NoShakeOffset, strtoul(ENCRYPT("0xC0035FD6"), nullptr, 0));
            }
        noshake_active = YES;
    }
    else{
        if(noshake_active == YES){
            vm_unity32(NoShakeOffset, strtoul(ENCRYPT("0xED33BB6D"), nullptr, 0));
            }
        noshake_active = NO;
    }

if(forcebuild){
        if(forcebuild_active == NO){
            vm_unity32(ForceBuildOffset, strtoul(ENCRYPT("0xC0035FD6"), nullptr, 0));
            }
        forcebuild_active = YES;
    }
    else{
        if(forcebuild_active == YES){
            vm_unity32(ForceBuildOffset, strtoul(ENCRYPT("0xFF8303D1"), nullptr, 0));
            }
        forcebuild_active = NO;
    }


if(mtt){
        if(mtt_active == NO){
            vm_unity32(MttOffset1, strtoul(ENCRYPT("0xC0035FD6"), nullptr, 0));
            vm_unity32(MttOffset2, strtoul(ENCRYPT("0xC0035FD6"), nullptr, 0));
            vm_unity32(MttOffset3, strtoul(ENCRYPT("0xC0035FD6"), nullptr, 0));
            vm_unity32(MttOffset4, strtoul(ENCRYPT("0xC0035FD6"), nullptr, 0));
            vm_unity32(MttOffset5, strtoul(ENCRYPT("0xC0035FD6"), nullptr, 0));
            vm_unity32(MttOffset6, strtoul(ENCRYPT("0xC0035FD6"), nullptr, 0));
            
            }
        mtt_active = YES;
    }
    else{
        if(mtt_active == YES){
            vm_unity32(MttOffset1, strtoul(ENCRYPT("0xC0035FD6"), nullptr, 0));
            vm_unity32(MttOffset2, strtoul(ENCRYPT("0xC0035FD6"), nullptr, 0));
            vm_unity32(MttOffset3, strtoul(ENCRYPT("0xC0035FD6"), nullptr, 0));
            vm_unity32(MttOffset4, strtoul(ENCRYPT("0xC0035FD6"), nullptr, 0));
            vm_unity32(MttOffset5, strtoul(ENCRYPT("0xC0035FD6"), nullptr, 0));
            vm_unity32(MttOffset1, strtoul(ENCRYPT("0xC0035FD6"), nullptr, 0));
            
            }
        mtt_active = NO;
    }

if(underwater){
        if(underwater_active == NO){
            vm_unity32(UnderWaterOffset, strtoul(ENCRYPT("0xC0035FD6"), nullptr, 0));
            }
        underwater_active = YES;
    }
    else{
        if(underwater_active == YES){
            vm_unity32(UnderWaterOffset, strtoul(ENCRYPT("0xED33B96D"), nullptr, 0));
            }
        underwater_active = NO;
    }

if(nofalldamage){
        if(nofalldamage_active == NO){
            vm_unity32(NoFallDamageOffset1, strtoul(ENCRYPT("0xC0035FD6"), nullptr, 0));
            vm_unity32(NoFallDamageOffset2, strtoul(ENCRYPT("0xC0035FD6"), nullptr, 0));
            vm_unity32(NoFallDamageOffset3, strtoul(ENCRYPT("0xC0035FD6"), nullptr, 0));
            }
        nofalldamage_active = YES;
    }
    else{
        if(nofalldamage_active == YES){
            vm_unity32(NoFallDamageOffset1, strtoul(ENCRYPT("0xE923BD6D"), nullptr, 0));
            vm_unity32(NoFallDamageOffset2, strtoul(ENCRYPT("0xF44FBEA9"), nullptr, 0));
            vm_unity32(NoFallDamageOffset3, strtoul(ENCRYPT("0xF85FBCA9"), nullptr, 0));
            }
        nofalldamage_active = NO;
    }

if(fakeowner){
        if(fakeowner_active == NO){
            vm_unity(FakeOwnerOffset1, strtoul(ENCRYPT("0x200080D2C0035FD6"), nullptr, 0));
            vm_unity(FakeOwnerOffset2, strtoul(ENCRYPT("0x200080D2C0035FD6"), nullptr, 0));
            vm_unity(FakeOwnerOffset3, strtoul(ENCRYPT("0x200080D2C0035FD6"), nullptr, 0));
            vm_unity(FakeOwnerOffset4, strtoul(ENCRYPT("0x200080D2C0035FD6"), nullptr, 0));
            }
        fakeowner_active = YES;
    }
    else{
        if(fakeowner_active == YES){
            vm_unity(FakeOwnerOffset1, strtoul(ENCRYPT("0x200080D2C0035FD6"), nullptr, 0));
            vm_unity(FakeOwnerOffset2, strtoul(ENCRYPT("0x200080D2C0035FD6"), nullptr, 0));
            vm_unity(FakeOwnerOffset3, strtoul(ENCRYPT("0x200080D2C0035FD6"), nullptr, 0));
            vm_unity(FakeOwnerOffset4, strtoul(ENCRYPT("0x200080D2C0035FD6"), nullptr, 0));
            }
        fakeowner_active = NO;
    }

if(nospread){
        if(nospread_active == NO){
            vm_unity32(NoSpreadOffset1, strtoul(ENCRYPT("0xC0035FD6"), nullptr, 0));
            vm_unity32(NoSpreadOffset2, strtoul(ENCRYPT("0xC0035FD6"), nullptr, 0));
            }
        nospread_active = YES;
    }
    else{
        if(nospread_active == YES){
            vm_unity32(NoSpreadOffset1, strtoul(ENCRYPT("0xEB2BBC6D"), nullptr, 0));
            vm_unity32(NoSpreadOffset2, strtoul(ENCRYPT("0xEB2BBC6D"), nullptr, 0));
            }
        nospread_active = NO;
    }

if(norecoil){
        if(norecoil_active == NO){
            vm_unity32(NoRecoilOffset, strtoul(ENCRYPT("0xC0035FD6"), nullptr, 0));
            }
        norecoil_active = YES;
    }
    else{
        if(norecoil_active == YES){
            vm_unity32(NoRecoilOffset, strtoul(ENCRYPT("0xEB2BBC6D"), nullptr, 0));
            }
        norecoil_active = NO;
    }

if(picture){
        if(picture_active == NO){
            vm_unity(PictureOffset, strtoul(ENCRYPT("0x200080D2C0035FD6"), nullptr, 0));
            }
        picture_active = YES;
    }
    else{
        if(picture_active == YES){
            vm_unity(PictureOffset, strtoul(ENCRYPT("0xF44FBEA9FD7B01A9"), nullptr, 0));
            }
        picture_active = NO;
    }

if(locktime){
        if(locktime_active == NO){
            vm_unity32(LockTimeOffset, strtoul(ENCRYPT("0xC0035FD6"), nullptr, 0));
            }
        locktime_active = YES;
    }
    else{
        if(locktime_active == YES){
            vm_unity32(LockTimeOffset, strtoul(ENCRYPT("0xF44FBEA9"), nullptr, 0));
            }
        locktime_active = NO;
    }

if(nograss){
        if(nograss_active == NO){
            vm_unity32(NoGrassOffset, strtoul(ENCRYPT("0xC0035FD6"), nullptr, 0));
            }
        nograss_active = YES;
    }
    else{
        if(nograss_active == YES){
            vm_unity32(NoGrassOffset, strtoul(ENCRYPT("0xF85FBCA9"), nullptr, 0));
            }
        nograss_active = NO;
    }

if(notree){
        if(notree_active == NO){
            vm_unity32(NoTreeOffset, strtoul(ENCRYPT("0xC0035FD6"), nullptr, 0));
            }
        notree_active = YES;
    }
    else{
        if(notree_active == YES){
            vm_unity32(NoTreeOffset, strtoul(ENCRYPT("0xF657BDA9"), nullptr, 0));
            }
        notree_active = NO;
    }



if(name){
        if(name_active == NO){
            vm_unity(NameOffset, strtoul(ENCRYPT("0x200080D2C0035FD6"), nullptr, 0));
            //vm_unity(ENCRYPTOFFSET("0x1167794"), strtoul(ENCRYPTHEX("0x200080D2C0035FD6"), nullptr, 0));
            }
        name_active = YES;
    }
    else{
        if(name_active == YES){
            vm_unity(NameOffset, strtoul(ENCRYPT("0x200080D2C0035FD6"), nullptr, 0));
            //vm_unity(ENCRYPTOFFSET("0x1167794"), strtoul(ENCRYPTHEX("0xF657BDA9F44F01A9"), nullptr, 0));
            }
        name_active = NO;
    }



    if(notexture){
        if(notexture_active == NO){
            vm_unity32(NoTextureOffset, strtoul(ENCRYPT("0xC0035FD6"), nullptr, 0));
            }
        notexture_active = YES;
    }
    else{
        if(notexture_active == YES){
            vm_unity32(NoTextureOffset, strtoul(ENCRYPT("0xF657BDA9"), nullptr, 0));
            }
        notexture_active = NO;
    }

if(bypass){
if(bypass_active == NO){	

vm_unity32(BpOff1, strtoul(ENCRYPT("0xC0035FD6"), nullptr, 0));
vm_unity32(BpOff2, strtoul(ENCRYPT("0xC0035FD6"), nullptr, 0));
vm_unity32(BpOff3, strtoul(ENCRYPT("0xC0035FD6"), nullptr, 0));
vm_unity32(BpOff4, strtoul(ENCRYPT("0xC0035FD6"), nullptr, 0));
vm_unity32(BpOff5, strtoul(ENCRYPT("0xC0035FD6"), nullptr, 0));
vm_unity32(BpOff6, strtoul(ENCRYPT("0xC0035FD6"), nullptr, 0));
vm_unity32(BpOff7, strtoul(ENCRYPT("0xC0035FD6"), nullptr, 0));

vm_unity32(BpOff8, strtoul(ENCRYPT("0xC0035FD6"), nullptr, 0));
vm_unity32(BpOff9, strtoul(ENCRYPT("0xC0035FD6"), nullptr, 0));
vm_unity32(BpOff10, strtoul(ENCRYPT("0xC0035FD6"), nullptr, 0));
vm_unity32(BpOff11, strtoul(ENCRYPT("0xC0035FD6"), nullptr, 0));
vm_unity32(BpOff12, strtoul(ENCRYPT("0xC0035FD6"), nullptr, 0));
vm_unity32(BpOff13, strtoul(ENCRYPT("0xC0035FD6"), nullptr, 0));
vm_unity32(BpOff14, strtoul(ENCRYPT("0xC0035FD6"), nullptr, 0));

vm_unity32(BpOff15, strtoul(ENCRYPT("0xC0035FD6"), nullptr, 0));
vm_unity32(BpOff16, strtoul(ENCRYPT("0xC0035FD6"), nullptr, 0));
vm_unity32(BpOff17, strtoul(ENCRYPT("0xC0035FD6"), nullptr, 0));
vm_unity32(BpOff18, strtoul(ENCRYPT("0xC0035FD6"), nullptr, 0));
vm_unity32(BpOff19, strtoul(ENCRYPT("0xC0035FD6"), nullptr, 0));
vm_unity(BpOff20, strtoul(ENCRYPT("0x200080D2C0035FD6"), nullptr, 0)); 
vm_unity(BpOff21, strtoul(ENCRYPT("0x200080D2C0035FD6"), nullptr, 0)); 

vm_unity(BpOff22, strtoul(ENCRYPT("0x200080D2C0035FD6"), nullptr, 0)); 
vm_unity32(BpOff23, strtoul(ENCRYPT("0xC0035FD6"), nullptr, 0));
vm_unity32(BpOff24, strtoul(ENCRYPT("0xC0035FD6"), nullptr, 0));
vm_unity32(BpOff27, strtoul(ENCRYPT("0xC0035FD6"), nullptr, 0));
vm_unity32(BpOff26, strtoul(ENCRYPT("0xC0035FD6"), nullptr, 0));
vm_unity32(BpOff28, strtoul(ENCRYPT("0xC0035FD6"), nullptr, 0));
vm_unity32(BpOff29, strtoul(ENCRYPT("0xC0035FD6"), nullptr, 0));
vm_unity32(BpOff30, strtoul(ENCRYPT("0xC0035FD6"), nullptr, 0));
vm_unity32(BpOff31, strtoul(ENCRYPT("0xC0035FD6"), nullptr, 0));
vm_unity32(BpOff32, strtoul(ENCRYPT("0xC0035FD6"), nullptr, 0));
vm_unity32(BpOff33, strtoul(ENCRYPT("0xC0035FD6"), nullptr, 0));
vm_unity32(BpOff34, strtoul(ENCRYPT("0xC0035FD6"), nullptr, 0));
vm_unity32(BpOff35, strtoul(ENCRYPT("0xC0035FD6"), nullptr, 0));
vm_unity32(BpOff36, strtoul(ENCRYPT("0xC0035FD6"), nullptr, 0));
vm_unity32(BpOff37, strtoul(ENCRYPT("0xC0035FD6"), nullptr, 0));
vm_unity32(BpOff37, strtoul(ENCRYPT("0xC0035FD6"), nullptr, 0));
vm_unity32(BpOff38, strtoul(ENCRYPT("0xC0035FD6"), nullptr, 0));
vm_unity32(BpOff39, strtoul(ENCRYPT("0xC0035FD6"), nullptr, 0));
vm_unity32(BpOff40, strtoul(ENCRYPT("0xC0035FD6"), nullptr, 0));
vm_unity32(BpOff41, strtoul(ENCRYPT("0xC0035FD6"), nullptr, 0));
vm_unity32(BpOff42, strtoul(ENCRYPT("0xC0035FD6"), nullptr, 0));
vm_unity32(BpOff43, strtoul(ENCRYPT("0xC0035FD6"), nullptr, 0));
vm_unity32(BpOff44, strtoul(ENCRYPT("0xC0035FD6"), nullptr, 0));
vm_unity32(BpOff45, strtoul(ENCRYPT("0xC0035FD6"), nullptr, 0));
vm_unity32(BpOff46, strtoul(ENCRYPT("0xC0035FD6"), nullptr, 0));
vm_unity32(BpOff47, strtoul(ENCRYPT("0xC0035FD6"), nullptr, 0));
vm_unity32(BpOff48, strtoul(ENCRYPT("0xC0035FD6"), nullptr, 0));
vm_unity32(BpOff49, strtoul(ENCRYPT("0xC0035FD6"), nullptr, 0));
vm_unity32(BpOff50, strtoul(ENCRYPT("0xC0035FD6"), nullptr, 0));
vm_unity32(BpOff51, strtoul(ENCRYPT("0xC0035FD6"), nullptr, 0));

/*vm_unity32(ENCRYPTOFFSET("0xE95A14"), strtoul(ENCRYPTHEX("0xC0035FD6"), nullptr, 0));
vm_unity32(ENCRYPTOFFSET("0xE95AE0"), strtoul(ENCRYPTHEX("0xC0035FD6"), nullptr, 0));
vm_unity32(ENCRYPTOFFSET("0xE95C68"), strtoul(ENCRYPTHEX("0xC0035FD6"), nullptr, 0));
vm_unity32(ENCRYPTOFFSET("0xE95CC0"), strtoul(ENCRYPTHEX("0xC0035FD6"), nullptr, 0));
vm_unity32(ENCRYPTOFFSET("0xE96E68"), strtoul(ENCRYPTHEX("0xC0035FD6"), nullptr, 0));
vm_unity32(ENCRYPTOFFSET("0xE96F14"), strtoul(ENCRYPTHEX("0xC0035FD6"), nullptr, 0));
vm_unity32(ENCRYPTOFFSET("0xE9718C"), strtoul(ENCRYPTHEX("0xC0035FD6"), nullptr, 0));
vm_unity32(ENCRYPTOFFSET("0xE96C88"), strtoul(ENCRYPTHEX("0xC0035FD6"), nullptr, 0));
vm_unity32(ENCRYPTOFFSET("0xE96D28"), strtoul(ENCRYPTHEX("0xC0035FD6"), nullptr, 0));
vm_unity32(ENCRYPTOFFSET("0xE96DC8"), strtoul(ENCRYPTHEX("0xC0035FD6"), nullptr, 0));
vm_unity32(ENCRYPTOFFSET("0xE9729C"), strtoul(ENCRYPTHEX("0xC0035FD6"), nullptr, 0));
vm_unity32(ENCRYPTOFFSET("0xE96BE8"), strtoul(ENCRYPTHEX("0xC0035FD6"), nullptr, 0));
vm_unity32(ENCRYPTOFFSET("0xE97D18"), strtoul(ENCRYPTHEX("0xC0035FD6"), nullptr, 0));
vm_unity32(ENCRYPTOFFSET("0xE9846C"), strtoul(ENCRYPTHEX("0xC0035FD6"), nullptr, 0));
vm_unity32(ENCRYPTOFFSET("0xE984C0"), strtoul(ENCRYPTHEX("0xC0035FD6"), nullptr, 0));
vm_unity32(ENCRYPTOFFSET("0xE985CC"), strtoul(ENCRYPTHEX("0xC0035FD6"), nullptr, 0));
vm_unity32(ENCRYPTOFFSET("0xE98068"), strtoul(ENCRYPTHEX("0xC0035FD6"), nullptr, 0));
vm_unity32(ENCRYPTOFFSET("0xE98A64"), strtoul(ENCRYPTHEX("0xC0035FD6"), nullptr, 0));
vm_unity32(ENCRYPTOFFSET("0xE98FD0"), strtoul(ENCRYPTHEX("0xC0035FD6"), nullptr, 0));
vm_unity32(ENCRYPTOFFSET("0xE99234"), strtoul(ENCRYPTHEX("0xC0035FD6"), nullptr, 0));
vm_unity32(ENCRYPTOFFSET("0xE97C1C"), strtoul(ENCRYPTHEX("0xC0035FD6"), nullptr, 0));
vm_unity32(ENCRYPTOFFSET("0xE9960C"), strtoul(ENCRYPTHEX("0xC0035FD6"), nullptr, 0));
vm_unity32(ENCRYPTOFFSET("0xE9967C"), strtoul(ENCRYPTHEX("0xC0035FD6"), nullptr, 0));
vm_unity32(ENCRYPTOFFSET("0xE996EC"), strtoul(ENCRYPTHEX("0xC0035FD6"), nullptr, 0));
vm_unity32(ENCRYPTOFFSET("0xE99780"), strtoul(ENCRYPTHEX("0xC0035FD6"), nullptr, 0));
vm_unity32(ENCRYPTOFFSET("0xE8CF9C"), strtoul(ENCRYPTHEX("0xC0035FD6"), nullptr, 0));*/

vm_unity32(BpOff52, strtoul(ENCRYPT("0xC0035FD6"), nullptr, 0));
vm_unity32(BpOff53, strtoul(ENCRYPT("0xC0035FD6"), nullptr, 0));
vm_unity32(BpOff54, strtoul(ENCRYPT("0xC0035FD6"), nullptr, 0));
vm_unity32(BpOff55, strtoul(ENCRYPT("0xC0035FD6"), nullptr, 0));
vm_unity32(BpOff56, strtoul(ENCRYPT("0xC0035FD6"), nullptr, 0));
vm_unity32(BpOff57, strtoul(ENCRYPT("0xC0035FD6"), nullptr, 0));
vm_unity32(BpOff58, strtoul(ENCRYPT("0xC0035FD6"), nullptr, 0));
vm_unity32(BpOff59, strtoul(ENCRYPT("0xC0035FD6"), nullptr, 0));
vm_unity32(BpOff60, strtoul(ENCRYPT("0xC0035FD6"), nullptr, 0));
vm_unity32(BpOff61, strtoul(ENCRYPT("0xC0035FD6"), nullptr, 0));
vm_unity32(BpOff62, strtoul(ENCRYPT("0xC0035FD6"), nullptr, 0));
vm_unity32(BpOff63, strtoul(ENCRYPT("0xC0035FD6"), nullptr, 0));

vm_unity32(BpOff64, strtoul(ENCRYPT("0xC0035FD6"), nullptr, 0));
vm_unity32(BpOff65, strtoul(ENCRYPT("0xC0035FD6"), nullptr, 0));
vm_unity32(BpOff66, strtoul(ENCRYPT("0xC0035FD6"), nullptr, 0));
vm_unity32(BpOff67, strtoul(ENCRYPT("0xC0035FD6"), nullptr, 0));
vm_unity32(BpOff68, strtoul(ENCRYPT("0xC0035FD6"), nullptr, 0));
vm_unity32(BpOff69, strtoul(ENCRYPT("0xC0035FD6"), nullptr, 0));
vm_unity32(BpOff70, strtoul(ENCRYPT("0xC0035FD6"), nullptr, 0));

vm_unity32(BpOff71, strtoul(ENCRYPT("0xC0035FD6"), nullptr, 0));
vm_unity32(BpOff72, strtoul(ENCRYPT("0xC0035FD6"), nullptr, 0));
vm_unity32(BpOff73, strtoul(ENCRYPT("0xC0035FD6"), nullptr, 0));
vm_unity32(BpOff74, strtoul(ENCRYPT("0xC0035FD6"), nullptr, 0));
vm_unity32(BpOff75, strtoul(ENCRYPT("0xC0035FD6"), nullptr, 0));
vm_unity32(BpOff76, strtoul(ENCRYPT("0xC0035FD6"), nullptr, 0));
vm_unity32(BpOff77, strtoul(ENCRYPT("0xC0035FD6"), nullptr, 0));

vm_unity32(BpOff78, strtoul(ENCRYPT("0xC0035FD6"), nullptr, 0));
vm_unity32(BpOff79, strtoul(ENCRYPT("0xC0035FD6"), nullptr, 0));
vm_unity32(BpOff80, strtoul(ENCRYPT("0xC0035FD6"), nullptr, 0));
vm_unity32(BpOff81, strtoul(ENCRYPT("0xC0035FD6"), nullptr, 0));
vm_unity32(BpOff82, strtoul(ENCRYPT("0xC0035FD6"), nullptr, 0));
vm_unity32(BpOff83, strtoul(ENCRYPT("0xC0035FD6"), nullptr, 0));
vm_unity32(BpOff84, strtoul(ENCRYPT("0xC0035FD6"), nullptr, 0));

vm_unity32(BpOff85, strtoul(ENCRYPT("0xC0035FD6"), nullptr, 0));

vm_unity32(BpOff86, strtoul(ENCRYPT("0xC0035FD6"), nullptr, 0));
vm_unity32(BpOff87, strtoul(ENCRYPT("0xC0035FD6"), nullptr, 0));
vm_unity32(BpOff88, strtoul(ENCRYPT("0xC0035FD6"), nullptr, 0));

vm_unity32(BpOff89, strtoul(ENCRYPT("0xC0035FD6"), nullptr, 0));
vm_unity32(BpOff90, strtoul(ENCRYPT("0xC0035FD6"), nullptr, 0));

vm_unity32(BpOff91, strtoul(ENCRYPT("0xC0035FD6"), nullptr, 0));
vm_unity32(BpOff92, strtoul(ENCRYPT("0xC0035FD6"), nullptr, 0));
vm_unity32(BpOff93, strtoul(ENCRYPT("0xC0035FD6"), nullptr, 0));

vm_unity32(BpOff94, strtoul(ENCRYPT("0xC0035FD6"), nullptr, 0));


            }
        bypass_active = YES;
    }
    else{
        if(bypass_active == YES){

            }
        bypass_active = NO;
    }


if(instantexp){
        if(instantexp_active == NO){
            vm_unity32(InstantExpOffset, strtoul(ENCRYPT("0xC0035FD6"), nullptr, 0));
            }
        instantexp_active = YES;
    }
    else{
        if(instantexp_active == YES){
            vm_unity32(InstantExpOffset, strtoul(ENCRYPT("0xE923BC6D"), nullptr, 0));
            }
        instantexp_active = NO;
    }

if(admesp){
        if(admesp_active == NO){
            vm_unity(AdmEspOffset, strtoul(ENCRYPT("0x200080D2C0035FD6"), nullptr, 0));
            }
        admesp_active = YES;
    }
    else{
        if(admesp_active == YES){
            vm_unity(AdmEspOffset, strtoul(ENCRYPT("0xF44FBEA9FD7B01A9"), nullptr, 0));
            }
        admesp_active = NO;
    }

if(noenemyanim){
        if(noenemyanim_active == NO){
            vm_unity32(NoEnemyAnimOffset1, strtoul(ENCRYPT("0xC0035FD6"), nullptr, 0));
            vm_unity32(NoEnemyAnimOffset2, strtoul(ENCRYPT("0xC0035FD6"), nullptr, 0));
            }
        noenemyanim_active = YES;
    }
    else{
        if(noenemyanim_active == YES){
            vm_unity32(NoEnemyAnimOffset1, strtoul(ENCRYPT("0xE923BB6D"), nullptr, 0));
            vm_unity32(NoEnemyAnimOffset2, strtoul(ENCRYPT("0xE923BB6D"), nullptr, 0));
            }
        noenemyanim_active = NO;
    }


if(traceroff){
        if(traceroff_active == NO){

            }
        traceroff_active = YES;
    }
    else{
        if(traceroff_active == YES){

            }
        traceroff_active = NO;
    }

if(rpgoff){
        if(rpgoff_active == NO){
            vm_unity32(RpgOffOffset, strtoul(ENCRYPT("0xC0035FD6"), nullptr, 0));
            }
        rpgoff_active = YES;
    }
    else{
        if(rpgoff_active == YES){
            vm_unity32(RpgOffOffset, strtoul(ENCRYPT("0xFF8301D1"), nullptr, 0));
            }
        rpgoff_active = NO;
    }

if(drinkwater){
        if(drinkwater_active == NO){
            vm_unity32(DrinkWaterOffset, strtoul(ENCRYPT("0xC0035FD6"), nullptr, 0));
            }
        drinkwater_active = YES;
    }
    else{
        if(drinkwater_active == YES){
            vm_unity32(DrinkWaterOffset, strtoul(ENCRYPT("0xF44FBEA9"), nullptr, 0));
            }
        drinkwater_active = NO;
    }

}


}