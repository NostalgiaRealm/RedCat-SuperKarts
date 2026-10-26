/*
 * FUN_0042d420 at 0042d420
 * undefined FUN_0042d420(void)
 * Address ranges: 0042d420-0042d460
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0042d420(void)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 local_8;
  undefined4 local_4;
  
  local_8 = 0;
  local_4 = 0;
  iVar1 = (**(code **)(*DAT_006a64a0 + 0x74))(DAT_006a64a0,8,&local_8);
  if (iVar1 != 0) {
    uVar2 = FUN_004b0190(iVar1);
    FUN_004afee0(s_Error_setting_color_key__s__004ea680,uVar2);
  }
  return;
}

