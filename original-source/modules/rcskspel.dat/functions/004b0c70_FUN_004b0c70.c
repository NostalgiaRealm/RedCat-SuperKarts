/*
 * FUN_004b0c70 at 004b0c70
 * undefined FUN_004b0c70(void)
 * Address ranges: 004b0c70-004b0d10
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_004b0c70(void)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  undefined4 local_4;
  
  if (DAT_006a64e4 != 0) {
    local_8 = DAT_004fe930;
    local_18 = DAT_004fe930;
    local_10 = 0;
    local_c = 0;
    local_4 = DAT_004fe934;
    local_20 = 0;
    local_1c = 0;
    local_14 = DAT_004fe934;
    FUN_004b08e0(DAT_006a64c0);
    FUN_004b08e0(DAT_006a64a0);
    iVar1 = (**(code **)(*DAT_006a64c0 + 0x14))
                      (DAT_006a64c0,&local_10,DAT_006a64a0,&local_20,0x1000000,0);
    if (iVar1 != 0) {
      uVar2 = FUN_004b0190(iVar1);
      FUN_004afee0(s__s__d____blitting_error___s___004feb9c,
                   s_C__libraries_dxdraw_Initlib_cpp_004feb14,0x65b,uVar2);
    }
  }
  return;
}

