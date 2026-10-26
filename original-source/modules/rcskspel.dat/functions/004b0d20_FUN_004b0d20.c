/*
 * FUN_004b0d20 at 004b0d20
 * undefined FUN_004b0d20(void)
 * Address ranges: 004b0d20-004b0e82
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_004b0d20(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5,undefined4 param_6)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 local_74;
  undefined4 local_70;
  undefined4 local_6c;
  undefined4 local_68;
  undefined4 local_64 [20];
  undefined4 local_14;
  
  local_74 = param_2;
  local_6c = param_4;
  local_68 = param_5;
  local_70 = param_3;
  local_64[0] = 100;
  if ((DAT_004fe938 == 0x10) || (DAT_004fe938 == 0x18)) {
    local_14 = param_6;
    if (DAT_006a6504 != 0) {
      local_14 = FUN_004b5740(param_6,0x18);
    }
  }
  else {
    local_14 = param_6;
  }
  if (param_1 == 0) {
    FUN_004b08e0(DAT_006a64bc);
    iVar1 = (**(code **)(*DAT_006a64bc + 0x14))(DAT_006a64bc,&local_74,0,0,0x1000400,local_64);
    if (iVar1 == 0) {
      return;
    }
    uVar2 = FUN_004b0190(iVar1);
    uVar3 = 0x6a0;
  }
  else if (param_1 == 1) {
    FUN_004b08e0(DAT_006a64c0);
    iVar1 = (**(code **)(*DAT_006a64c0 + 0x14))(DAT_006a64c0,&local_74,0,0,0x1000400,local_64);
    if (iVar1 == 0) {
      return;
    }
    uVar2 = FUN_004b0190(iVar1);
    uVar3 = 0x6b2;
  }
  else {
    if (param_1 != 2) {
      return;
    }
    FUN_004b08e0(DAT_006a64a0);
    iVar1 = (**(code **)(*DAT_006a64a0 + 0x14))(DAT_006a64a0,&local_74,0,0,0x1000400,local_64);
    if (iVar1 == 0) {
      return;
    }
    uVar2 = FUN_004b0190(iVar1);
    uVar3 = 0x6a9;
  }
  FUN_004afee0(s__s__d____blitting_error___s___004feb9c,s_C__libraries_dxdraw_Initlib_cpp_004feb14,
               uVar3,uVar2);
  return;
}

