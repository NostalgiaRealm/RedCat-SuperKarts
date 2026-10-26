/*
 * FUN_00472ce0 at 00472ce0
 * undefined FUN_00472ce0(void)
 * Address ranges: 00472ce0-00472e67
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 FUN_00472ce0(undefined4 param_1,undefined4 param_2)

{
  bool bVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  undefined2 uVar5;
  undefined4 uStack_14;
  undefined4 uStack_10;
  undefined4 uStack_c;
  undefined4 uStack_8;
  undefined2 uStack_4;
  
  bVar1 = false;
  FUN_004afce0(s_load_tga_surface___s__004f7110,param_2);
  iVar2 = FUN_004bf445(param_2,&DAT_004f7128);
  if (iVar2 == 0) {
    iVar2 = FUN_004b96d0(param_2);
    if (iVar2 == 0) {
      FUN_004afee0(s__s__d___load_tga_surface__s__cou_004f7150,
                   s_D__work_rcsk_Code_game_rrrtga_cp_004f712c,600,param_2);
    }
    bVar1 = true;
  }
  FUN_004c03bd(iVar2,0,0,0x1000);
  if (bVar1) {
    FUN_004b9570();
  }
  else {
    FUN_004c0331(iVar2,0,0);
  }
  uVar5 = 0;
  FUN_004bf930(&uStack_14,0x12,1,iVar2);
  if ((*(byte *)(iVar2 + 0xc) & 0x20) != 0) {
    uVar4 = param_2;
    FUN_004afee0(s__s__d___load_tga_surface__s__rea_004f71a8,
                 s_D__work_rcsk_Code_game_rrrtga_cp_004f7184,0x267,param_2,
                 (&PTR_s_No_error_00502a20)[DAT_006b66ec]);
    uVar5 = (undefined2)((uint)uVar4 >> 0x10);
  }
  if ((char)uStack_14 != '\0') {
    if (bVar1) {
      iVar3 = (int)(char)uStack_14;
      FUN_004b9570(iVar2,iVar3);
      uVar5 = (undefined2)((uint)iVar3 >> 0x10);
    }
    else {
      iVar3 = (int)(char)uStack_14;
      FUN_004c0331(iVar2,iVar3,1);
      uVar5 = (undefined2)((uint)iVar3 >> 0x10);
    }
  }
  if ((char)uStack_4 < '\x18') {
    uVar5 = 0;
    FUN_004afee0(s__s__d___load_tga_surface__s__Inv_004f7200,
                 s_D__work_rcsk_Code_game_rrrtga_cp_004f71dc,0x273,param_2);
  }
  if ('\x03' < uStack_14._2_1_) {
    FUN_004afee0(s__s__d___load_tga_surface__s___Do_004f7258,
                 s_D__work_rcsk_Code_game_rrrtga_cp_004f7234,0x277,param_2,(int)uStack_14._2_1_);
    uVar5 = (undefined2)((uint)param_2 >> 0x10);
  }
  FUN_00472a50(param_1,uStack_14,uStack_10,uStack_c,uStack_8,CONCAT22(uVar5,uStack_4),iVar2);
  if (!bVar1) {
    FUN_004bf2c5(iVar2);
    return 0;
  }
  FUN_004b9840();
  return 0;
}

