void initial_setup(){
    Il2CppAttach();   
    Il2CppMethod& getClass(const char* namespaze, const char* className);
    uintptr_t getMethod(const char* methodName, int argsCount);
    Il2CppMethod methodAccess(ENC("Assembly-CSharp.dll")); 
    Il2CppMethod Physics(ENC("UnityEngine.PhysicsModule.dll")); 
    Il2CppMethod Transform(ENC("UnityEngine.CoreModule.dll")); 
    Il2CppMethod mscorlib(ENC("mscorlib.dll")); 

   

    /*GmOpenMethod = methodAccess.getClass(ENCRYPT("SC.UI"), ENCRYPT("BattlePanel")).getMethod(ENCRYPT("ShowGm"), 0); 
    GmCloseMethod = methodAccess.getClass(ENCRYPT("SC.UI"), ENCRYPT("BattlePanel")).getMethod(ENCRYPT("CloseGm"), 0); 
    GmUpdateMethod = methodAccess.getClass(ENCRYPT("SC.UI"), ENCRYPT("BattlePanel")).getMethod(ENCRYPT("Update"), 0); 


    HOOK(GmOpenMethod, ShowGm, Old_ShowGm); 
    HOOK(GmCloseMethod, CloseGm, Old_CloseGm); 
    HOOK(GmUpdateMethod, UpdateGm, Old_UpdateGm);    

    GunDoOneShootMethod = methodAccess.getClass(ENCRYPT(""), ENCRYPT("Gun")).getMethod(ENCRYPT("DoOneShoot"), 0); 
    HOOK(GunDoOneShootMethod, Gun_DoOneShoot, Old_Gun_DoOneShoot);   

    GetFootGroundDisMethod = methodAccess.getClass(ENCRYPT(""), ENCRYPT("PlayerController")).getMethod(ENCRYPT("GetFootGroundDis"), 0); 
    HOOK(GetFootGroundDisMethod, PlayerController_GetFootGroundDis, Old_PlayerController_GetFootGroundDis);   */



GetTypeOffset = mscorlib.getClass(ENCRYPT("System"), ENCRYPT("Type")).getMethod(ENCRYPT("GetType"), 1);
FindObjectsOffset = Transform.getClass(ENCRYPT("UnityEngine"), ENCRYPT("Object")).getMethod(ENCRYPT("FindObjectsOfType"), 1);      
GetNameOffset = methodAccess.getClass(ENCRYPT(""), ENCRYPT("OtherPlayerController")).getMethod(ENCRYPT("GetPlayerNick"), 0);
GetName2Offset = Transform.getClass(ENCRYPT("UnityEngine"), ENCRYPT("Object")).getMethod(ENCRYPT("GetName"), 1);    
GetPlayerInfoOffset = methodAccess.getClass(ENCRYPT(""), ENCRYPT("BasePlayerController")).getMethod(ENCRYPT("get_PlayerInfo"), 0);  
FindObjectOffset = Transform.getClass(ENCRYPT("UnityEngine"), ENCRYPT("Object")).getMethod(ENCRYPT("FindObjectOfType"), 1);      
GetRigidbodyOffset = methodAccess.getClass(ENCRYPT(""), ENCRYPT("PlayerController")).getMethod(ENCRYPT("get_PlayerRigidbody"), 0);


NoGrassOffset = methodAccess.getClass(ENCRYPT(""), ENCRYPT("GrassObject")).getMethod(ENCRYPT("AddToScene"), 1);
ExtendedBuildOffset = methodAccess.getClass(ENCRYPT("EasyBuildSystem.Runtimes.Internal.Builder"), ENCRYPT("BuilderBehaviour")).getMethod(ENCRYPT("UpdatePreviewCollisions"), 1);
SoulOffset = methodAccess.getClass(ENCRYPT(""), ENCRYPT("Battle")).getMethod(ENCRYPT("OnSServerPullBack"), 1);
NoShakeOffset = methodAccess.getClass(ENCRYPT(""), ENCRYPT("PlayerController")).getMethod(ENCRYPT("OnLandMineEvent"), 1);
ForceBuildOffset = methodAccess.getClass(ENCRYPT("EasyBuildSystem.Runtimes.Internal.Part"), ENCRYPT("PartBehaviour")).getMethod(ENCRYPT("CheckEnterBoxCollider"), 0);
MttOffset1 = methodAccess.getClass(ENCRYPT(""), ENCRYPT("SystemHelicopterBehaviourController")).getMethod(ENCRYPT("Fire"), 3);
MttOffset2 = methodAccess.getClass(ENCRYPT(""), ENCRYPT("SystemTankController")).getMethod(ENCRYPT("Fire"), 3);
MttOffset3 = methodAccess.getClass(ENCRYPT(""), ENCRYPT("MonsterController")).getMethod(ENCRYPT("SetTarget"), 1);
MttOffset4 = methodAccess.getClass(ENCRYPT(""), ENCRYPT("MonsterController")).getMethod(ENCRYPT("AnimalMove"), 0);
MttOffset5 = methodAccess.getClass(ENCRYPT(""), ENCRYPT("TurretGameObject")).getMethod(ENCRYPT("SetTarget"), 1);
MttOffset6 = methodAccess.getClass(ENCRYPT(""), ENCRYPT("ElectricTurretGameObject")).getMethod(ENCRYPT("SetTarget"), 1);
UnderWaterOffset = methodAccess.getClass(ENCRYPT(""), ENCRYPT("SwimState")).getMethod(ENCRYPT("CheckSwim"), 0);
NoFallDamageOffset1 = methodAccess.getClass(ENCRYPT(""), ENCRYPT("FallState")).getMethod(ENCRYPT("DoHit"), 0);
NoFallDamageOffset2 = methodAccess.getClass(ENCRYPT(""), ENCRYPT("FallState")).getMethod(ENCRYPT("CheckEnterFall"), 0);
NoFallDamageOffset3 = methodAccess.getClass(ENCRYPT(""), ENCRYPT("FallState")).getMethod(ENCRYPT("Init"), 0);
FakeOwnerOffset1 = methodAccess.getClass(ENCRYPT(""), ENCRYPT("FriendPermitMgr")).getMethod(ENCRYPT("HavePermit"), 1);
FakeOwnerOffset2 = methodAccess.getClass(ENCRYPT(""), ENCRYPT("FriendPermitMgr")).getMethod(ENCRYPT("HavePermitByInstanceId"), 1);
FakeOwnerOffset3 = methodAccess.getClass(ENCRYPT(""), ENCRYPT("FriendPermitMgr")).getMethod(ENCRYPT("OtherBoxPermit"), 1);
FakeOwnerOffset4 = methodAccess.getClass(ENCRYPT("EasyBuildSystem.Runtimes.Internal.Part"), ENCRYPT("PartBehaviour")).getMethod(ENCRYPT("get_HavePermit"), 0);
NoSpreadOffset1 = methodAccess.getClass(ENCRYPT(""), ENCRYPT("Gun")).getMethod(ENCRYPT("CaulateShootAimRadius"), 0);
NoSpreadOffset2 = methodAccess.getClass(ENCRYPT(""), ENCRYPT("Gun")).getMethod(ENCRYPT("CaulateMoveAimRadius"), 0);
NoRecoilOffset = methodAccess.getClass(ENCRYPT(""), ENCRYPT("Gun")).getMethod(ENCRYPT("CalulateOffsetAngle"), 3);
PictureOffset = methodAccess.getClass(ENCRYPT(""), ENCRYPT("InDoorTrigger")).getMethod(ENCRYPT("IsInDoor"), 0);
LockTimeOffset = methodAccess.getClass(ENCRYPT(""), ENCRYPT("DayNightSystem")).getMethod(ENCRYPT("Update"), 0);
NoTreeOffset = methodAccess.getClass(ENCRYPT(""), ENCRYPT("TreeObject")).getMethod(ENCRYPT("AddToScene"), 1);
NameOffset = methodAccess.getClass(ENCRYPT(""), ENCRYPT("UnionMgr")).getMethod(ENCRYPT("IsSameUnion"), 1);
NoTextureOffset = methodAccess.getClass(ENCRYPT(""), ENCRYPT("ThingsObject")).getMethod(ENCRYPT("AddToScene"), 1);
NoTextureOffset = methodAccess.getClass(ENCRYPT(""), ENCRYPT("ThingsObject")).getMethod(ENCRYPT("AddToScene"), 1);
BpOff1 = methodAccess.getClass(ENCRYPT(""), ENCRYPT("PlayerController")).getMethod(ENCRYPT("GetFootGroundDis"), 0);
BpOff2 = methodAccess.getClass(ENCRYPT(""), ENCRYPT("PlayerController")).getMethod(ENCRYPT("CheckGroundDistance"), 0);
BpOff3 = methodAccess.getClass(ENCRYPT(""), ENCRYPT("PlayerController")).getMethod(ENCRYPT("CheckUnderGround"), 0);
BpOff4 = methodAccess.getClass(ENCRYPT(""), ENCRYPT("HeartMgr")).getMethod(ENCRYPT("CheckUnderGround"), 0);
BpOff5 = methodAccess.getClass(ENCRYPT(""), ENCRYPT("HeartMgr")).getMethod(ENCRYPT("CheckFly"), 0);
BpOff6 = methodAccess.getClass(ENCRYPT(""), ENCRYPT("MailMgr")).getMethod(ENCRYPT("CheckUnderGround"), 0);
BpOff7 = methodAccess.getClass(ENCRYPT(""), ENCRYPT("MailMgr")).getMethod(ENCRYPT("CheckFly"), 0);
BpOff8 = methodAccess.getClass(ENCRYPT("gs.cheating_report.scmsg"), ENCRYPT("CHeartBeat")).getMethod(ENCRYPT(".ctor"), 0);
BpOff9 = methodAccess.getClass(ENCRYPT("gs.cheating_report.scmsg"), ENCRYPT("CHeartBeat")).getMethod(ENCRYPT("handle"), 0);
BpOff10 = methodAccess.getClass(ENCRYPT("gs.cheating_report.scmsg"), ENCRYPT("CHeartBeat")).getMethod(ENCRYPT("getType"), 0);
BpOff11 = methodAccess.getClass(ENCRYPT("gs.cheating_report.scmsg"), ENCRYPT("CHeartBeat")).getMethod(ENCRYPT("marshal"), 1);
BpOff12 = methodAccess.getClass(ENCRYPT("gs.cheating_report.scmsg"), ENCRYPT("CHeartBeat")).getMethod(ENCRYPT("unmarshal"), 1);
BpOff13 = methodAccess.getClass(ENCRYPT("gs.cheating_report.scmsg"), ENCRYPT("CHeartBeat")).getMethod(ENCRYPT("marshal"), 2);
BpOff14 = methodAccess.getClass(ENCRYPT("gs.cheating_report.scmsg"), ENCRYPT("CHeartBeat")).getMethod(ENCRYPT("unmarshal"), 2);
BpOff15 = methodAccess.getClass(ENCRYPT(""), ENCRYPT("CheatMgr")).getMethod(ENCRYPT("OnSInspectPlayerMgs"), 1);
BpOff16 = methodAccess.getClass(ENCRYPT(""), ENCRYPT("CheatMgr")).getMethod(ENCRYPT("OnSGetAntiCheatingReward"), 1);
BpOff17 = methodAccess.getClass(ENCRYPT(""), ENCRYPT("CheatMgr")).getMethod(ENCRYPT("OnSAntiCheatingInfo"), 1);
BpOff18 = methodAccess.getClass(ENCRYPT(""), ENCRYPT("CheatMgr")).getMethod(ENCRYPT("SendCGetAntiCheatingReward"), 0);
BpOff19 = methodAccess.getClass(ENCRYPT(""), ENCRYPT("CheatMgr")).getMethod(ENCRYPT("SendCGetFaceToken"), 2);
BpOff20 = methodAccess.getClass(ENCRYPT(""), ENCRYPT("CheatMgr")).getMethod(ENCRYPT("isVerifyIphone"), 0);
BpOff21 = methodAccess.getClass(ENCRYPT(""), ENCRYPT("CheatMgr")).getMethod(ENCRYPT("isVerify"), 0);
BpOff22 = methodAccess.getClass(ENCRYPT(""), ENCRYPT("PlatformMgr")).getMethod(ENCRYPT("get_IsTest"), 0);
BpOff23 = methodAccess.getClass(ENCRYPT(""), ENCRYPT("PlatformMgr")).getMethod(ENCRYPT("ReportToThinkData"), 3);
BpOff24 = methodAccess.getClass(ENCRYPT(""), ENCRYPT("PlatformMgr")).getMethod(ENCRYPT("ReportToNewBDC"), 2);
BpOff25 = methodAccess.getClass(ENCRYPT(""), ENCRYPT("PlatformMgr")).getMethod(ENCRYPT("ReportEventMessage"), 2);
BpOff26 = methodAccess.getClass(ENCRYPT(""), ENCRYPT("PlatformMgr")).getMethod(ENCRYPT("ReportEventMessage"), 2);

BpOff27 = methodAccess.getClass(ENCRYPT(""), ENCRYPT("PlatformMgr")).getMethod(ENCRYPT("ReportOpenPanel"), 1);
BpOff28 = methodAccess.getClass(ENCRYPT(""), ENCRYPT("PlatformMgr")).getMethod(ENCRYPT("FlushToThinkData"), 2);
BpOff29 = methodAccess.getClass(ENCRYPT(""), ENCRYPT("PlatformMgr")).getMethod(ENCRYPT("FlushToThinkData"), 2);
BpOff30 = methodAccess.getClass(ENCRYPT(""), ENCRYPT("PlatformMgr")).getMethod(ENCRYPT("FlushAllToThinkData"), 1);
BpOff31 = methodAccess.getClass(ENCRYPT(""), ENCRYPT("PlatformMgr")).getMethod(ENCRYPT("ReportLogin"), 2);
BpOff32 = methodAccess.getClass(ENCRYPT(""), ENCRYPT("PlatformMgr")).getMethod(ENCRYPT("ReportIosSplashEvent"), 0);
BpOff33 = methodAccess.getClass(ENCRYPT(""), ENCRYPT("PlatformMgr")).getMethod(ENCRYPT("ReportBattleTime"), 1);
BpOff34 = methodAccess.getClass(ENCRYPT(""), ENCRYPT("PlatformMgr")).getMethod(ENCRYPT("ReportBattleTime"), 1);
BpOff35 = methodAccess.getClass(ENCRYPT(""), ENCRYPT("PlatformMgr")).getMethod(ENCRYPT("ReportChargeNum"), 1);
BpOff36 = methodAccess.getClass(ENCRYPT(""), ENCRYPT("PlatformMgr")).getMethod(ENCRYPT("ToReportAppsflyer"), 1);
BpOff37 = methodAccess.getClass(ENCRYPT(""), ENCRYPT("PlatformMgr")).getMethod(ENCRYPT("ReportDataToAppsflyer"), 1);
BpOff38 = methodAccess.getClass(ENCRYPT(""), ENCRYPT("PlatformMgr")).getMethod(ENCRYPT("ToReportAppsflyer"), 2);
BpOff39 = methodAccess.getClass(ENCRYPT(""), ENCRYPT("PlatformMgr")).getMethod(ENCRYPT("OnAppQuit"), 0);
BpOff40 = methodAccess.getClass(ENCRYPT(""), ENCRYPT("PlatformMgr")).getMethod(ENCRYPT("OnReportIsSoFiles"), 2);
BpOff41 = methodAccess.getClass(ENCRYPT(""), ENCRYPT("PlatformMgr")).getMethod(ENCRYPT("OnReportIsPeripheral"), 0);
BpOff42 = methodAccess.getClass(ENCRYPT(""), ENCRYPT("PlatformMgr")).getMethod(ENCRYPT("OnReportIsRoot"), 0);
BpOff43 = methodAccess.getClass(ENCRYPT(""), ENCRYPT("PlatformMgr")).getMethod(ENCRYPT("OnReportIsFridaHook"), 0);
BpOff44 = methodAccess.getClass(ENCRYPT(""), ENCRYPT("PlatformMgr")).getMethod(ENCRYPT("OnReportIsCertFileMd5"), 0);
BpOff45 = methodAccess.getClass(ENCRYPT(""), ENCRYPT("PlatformMgr")).getMethod(ENCRYPT("OnReportIllegalIdentifier"), 0);
BpOff46 = methodAccess.getClass(ENCRYPT(""), ENCRYPT("PlatformMgr")).getMethod(ENCRYPT("ReportToBDC"), 1);
BpOff47 = methodAccess.getClass(ENCRYPT(""), ENCRYPT("PlatformMgr")).getMethod(ENCRYPT("ReportToBDC"), 1);
BpOff48 = methodAccess.getClass(ENCRYPT(""), ENCRYPT("PlatformMgr")).getMethod(ENCRYPT("MTP_DETECT_RESULTToBDC"), 1);
BpOff49 = methodAccess.getClass(ENCRYPT(""), ENCRYPT("PlatformMgr")).getMethod(ENCRYPT("MTP_HEARTBEATToBDC"), 4);
BpOff50 = methodAccess.getClass(ENCRYPT(""), ENCRYPT("PlatformMgr")).getMethod(ENCRYPT("CertMd5ToBDC"), 1);
BpOff51 = methodAccess.getClass(ENCRYPT(""), ENCRYPT("PlatformMgr")).getMethod(ENCRYPT("ReportClientKillSelf"), 3);
BpOff52 = methodAccess.getClass(ENCRYPT(""), ENCRYPT("HeartMgr")).getMethod(ENCRYPT("Init"), 0);
BpOff53 = methodAccess.getClass(ENCRYPT(""), ENCRYPT("HeartMgr")).getMethod(ENCRYPT("TickSend"), 0);
BpOff54 = methodAccess.getClass(ENCRYPT(""), ENCRYPT("HeartMgr")).getMethod(ENCRYPT("TickMtp"), 0);
BpOff55 = methodAccess.getClass(ENCRYPT(""), ENCRYPT("HeartMgr")).getMethod(ENCRYPT("Tick"), 0);
BpOff56 = methodAccess.getClass(ENCRYPT(""), ENCRYPT("HeartMgr")).getMethod(ENCRYPT("CheckCamera"), 0);
BpOff57 = methodAccess.getClass(ENCRYPT(""), ENCRYPT("HeartMgr")).getMethod(ENCRYPT("CheckAnimOverSpeed"), 0);
BpOff58 = methodAccess.getClass(ENCRYPT(""), ENCRYPT("HeartMgr")).getMethod(ENCRYPT("CheckThrougthWall"), 0);
BpOff59 = methodAccess.getClass(ENCRYPT(""), ENCRYPT("HeartMgr")).getMethod(ENCRYPT("Dosome"), 1);
BpOff60 = methodAccess.getClass(ENCRYPT(""), ENCRYPT("HeartMgr")).getMethod(ENCRYPT("CheckMsgToSend"), 0);
BpOff61 = methodAccess.getClass(ENCRYPT(""), ENCRYPT("HeartMgr")).getMethod(ENCRYPT("CheckMainFunsNotMsg"), 0);
BpOff62 = methodAccess.getClass(ENCRYPT(""), ENCRYPT("HeartMgr")).getMethod(ENCRYPT("CheckHeartLive"), 0);
BpOff63 = methodAccess.getClass(ENCRYPT(""), ENCRYPT("HeartMgr")).getMethod(ENCRYPT("ForceQuitCheckUserGua"), 0);
BpOff64 = methodAccess.getClass(ENCRYPT("gs.anticheating.scmsg"), ENCRYPT("CGetAntiCheatingReward")).getMethod(ENCRYPT(".ctor"), 0);
BpOff65 = methodAccess.getClass(ENCRYPT("gs.anticheating.scmsg"), ENCRYPT("CGetAntiCheatingReward")).getMethod(ENCRYPT("handle"), 0);
BpOff66 = methodAccess.getClass(ENCRYPT("gs.anticheating.scmsg"), ENCRYPT("CGetAntiCheatingReward")).getMethod(ENCRYPT("getType"), 0);
BpOff67 = methodAccess.getClass(ENCRYPT("gs.anticheating.scmsg"), ENCRYPT("CGetAntiCheatingReward")).getMethod(ENCRYPT("marshal"), 1);
BpOff68 = methodAccess.getClass(ENCRYPT("gs.anticheating.scmsg"), ENCRYPT("CGetAntiCheatingReward")).getMethod(ENCRYPT("unmarshal"), 1);
BpOff69 = methodAccess.getClass(ENCRYPT("gs.anticheating.scmsg"), ENCRYPT("CGetAntiCheatingReward")).getMethod(ENCRYPT("marshal"), 2);
BpOff70 = methodAccess.getClass(ENCRYPT("gs.anticheating.scmsg"), ENCRYPT("CGetAntiCheatingReward")).getMethod(ENCRYPT("unmarshal"), 2);
BpOff71 = methodAccess.getClass(ENCRYPT("gs.anticheating.scmsg"), ENCRYPT("SAntiCheatingInfo")).getMethod(ENCRYPT(".ctor"), 0);
BpOff72 = methodAccess.getClass(ENCRYPT("gs.anticheating.scmsg"), ENCRYPT("SAntiCheatingInfo")).getMethod(ENCRYPT("handle"), 0);
BpOff73 = methodAccess.getClass(ENCRYPT("gs.anticheating.scmsg"), ENCRYPT("SAntiCheatingInfo")).getMethod(ENCRYPT("getType"), 0);
BpOff74 = methodAccess.getClass(ENCRYPT("gs.anticheating.scmsg"), ENCRYPT("SAntiCheatingInfo")).getMethod(ENCRYPT("marshal"), 1);
BpOff75 = methodAccess.getClass(ENCRYPT("gs.anticheating.scmsg"), ENCRYPT("SAntiCheatingInfo")).getMethod(ENCRYPT("unmarshal"), 1);
BpOff76 = methodAccess.getClass(ENCRYPT("gs.anticheating.scmsg"), ENCRYPT("SAntiCheatingInfo")).getMethod(ENCRYPT("marshal"), 2);
BpOff77 = methodAccess.getClass(ENCRYPT("gs.anticheating.scmsg"), ENCRYPT("SAntiCheatingInfo")).getMethod(ENCRYPT("unmarshal"), 2);
BpOff78 = methodAccess.getClass(ENCRYPT("gs.anticheating.scmsg"), ENCRYPT("SGetAntiCheatingReward")).getMethod(ENCRYPT(".ctor"), 0);
BpOff79 = methodAccess.getClass(ENCRYPT("gs.anticheating.scmsg"), ENCRYPT("SGetAntiCheatingReward")).getMethod(ENCRYPT("handle"), 0);
BpOff80 = methodAccess.getClass(ENCRYPT("gs.anticheating.scmsg"), ENCRYPT("SGetAntiCheatingReward")).getMethod(ENCRYPT("getType"), 0);
BpOff81 = methodAccess.getClass(ENCRYPT("gs.anticheating.scmsg"), ENCRYPT("SGetAntiCheatingReward")).getMethod(ENCRYPT("marshal"), 1);
BpOff82 = methodAccess.getClass(ENCRYPT("gs.anticheating.scmsg"), ENCRYPT("SGetAntiCheatingReward")).getMethod(ENCRYPT("unmarshal"), 1);
BpOff83 = methodAccess.getClass(ENCRYPT("gs.anticheating.scmsg"), ENCRYPT("SGetAntiCheatingReward")).getMethod(ENCRYPT("marshal"), 2);
BpOff84 = methodAccess.getClass(ENCRYPT("gs.anticheating.scmsg"), ENCRYPT("SGetAntiCheatingReward")).getMethod(ENCRYPT("unmarshal"), 2);
BpOff85 = methodAccess.getClass(ENCRYPT(""), ENCRYPT("CMtpReceiver")).getMethod(ENCRYPT("Init"), 0);
BpOff86 = methodAccess.getClass(ENCRYPT(""), ENCRYPT("CMtpReceiver")).getMethod(ENCRYPT("CheckBroadcastInfo"), 1);
BpOff87 = methodAccess.getClass(ENCRYPT(""), ENCRYPT("CMtpReceiver")).getMethod(ENCRYPT("CheckBroadcastInfoForBDC"), 1);
BpOff88 = methodAccess.getClass(ENCRYPT(""), ENCRYPT("CMtpReceiver")).getMethod(ENCRYPT("reportCloudPhone"), 1);
BpOff89 = methodAccess.getClass(ENCRYPT(""), ENCRYPT("PlatformMgr")).getMethod(ENCRYPT("ReportLogin"), 2);
BpOff90 = methodAccess.getClass(ENCRYPT(""), ENCRYPT("PlatformMgr")).getMethod(ENCRYPT("ReportLogOut"), 0);
BpOff91 = methodAccess.getClass(ENCRYPT(""), ENCRYPT("PlatformMgr")).getMethod(ENCRYPT("ReportUserSet"), 1);
BpOff92 = methodAccess.getClass(ENCRYPT(""), ENCRYPT("PlatformMgr")).getMethod(ENCRYPT("ReportUserSetOnce"), 1);
BpOff93 = methodAccess.getClass(ENCRYPT(""), ENCRYPT("PlatformMgr")).getMethod(ENCRYPT("ReportUserAdd"), 1);
BpOff94 = methodAccess.getClass(ENCRYPT(""), ENCRYPT("PlatformMgr")).getMethod(ENCRYPT("CheckMemory"), 5);
InstantExpOffset = methodAccess.getClass(ENCRYPT(""), ENCRYPT("LandMineMgr")).getMethod(ENCRYPT("GetDelayTime"), 1);
AdmEspOffset = methodAccess.getClass(ENCRYPT(""), ENCRYPT("Battle")).getMethod(ENCRYPT("IsLookModel"), 0);
NoEnemyAnimOffset1 = methodAccess.getClass(ENCRYPT(""), ENCRYPT("MonsterController")).getMethod(ENCRYPT("PlayerAnimation"), 2);
NoEnemyAnimOffset2 = methodAccess.getClass(ENCRYPT(""), ENCRYPT("MonsterController")).getMethod(ENCRYPT("PlayerAnimation"), 2);
RpgOffOffset = methodAccess.getClass(ENCRYPT(""), ENCRYPT("BulletControl")).getMethod(ENCRYPT("playBombEffect"), 1);
DrinkWaterOffset = methodAccess.getClass(ENCRYPT(""), ENCRYPT("PlayerController")).getMethod(ENCRYPT("CheckNearWater"), 0);



SetVelocityOffset = Physics.getClass(ENCRYPT("UnityEngine"), ENCRYPT("Rigidbody")).getMethod(ENCRYPT("set_velocity"), 1);
GetVelocityOffset = Physics.getClass(ENCRYPT("UnityEngine"), ENCRYPT("Rigidbody")).getMethod(ENCRYPT("get_velocity"), 0);
SetIsKinematicOffset = Physics.getClass(ENCRYPT("UnityEngine"), ENCRYPT("Rigidbody")).getMethod(ENCRYPT("set_isKinematic"), 1);
SetGroundedOffset = methodAccess.getClass(ENCRYPT(""), ENCRYPT("PlayerController")).getMethod(ENCRYPT("set_Grounded"), 1);
SetDetectCollisionsOffset = Physics.getClass(ENCRYPT("UnityEngine"), ENCRYPT("Rigidbody")).getMethod(ENCRYPT("set_detectCollisions"), 1);  
GetPositionOffset = Transform.getClass(ENCRYPT("UnityEngine"), ENCRYPT("Transform")).getMethod(ENCRYPT("get_position"), 0);    
GetForwardOffset = Transform.getClass(ENCRYPT("UnityEngine"), ENCRYPT("Transform")).getMethod(ENCRYPT("get_forward"), 0);    
GetTransformOffset = Transform.getClass(ENCRYPT("UnityEngine"), ENCRYPT("Component")).getMethod(ENCRYPT("get_transform"), 0);    
CameraOffset = Transform.getClass(ENCRYPT("UnityEngine"), ENCRYPT("Camera")).getMethod(ENCRYPT("get_main"), 0);      
W2WPOffset = Transform.getClass(ENCRYPT("UnityEngine"), ENCRYPT("Camera")).getMethod(ENCRYPT("WorldToViewportPoint"), 1);      
IsAliveObjectOffset = Transform.getClass(ENCRYPT("UnityEngine"), ENCRYPT("Object")).getMethod(ENCRYPT("IsNativeObjectAlive"), 1);      
SetPositionOffset = Transform.getClass(ENCRYPT("UnityEngine"), ENCRYPT("Transform")).getMethod(ENCRYPT("set_position"), 1);        

   
}

