/*
 * FUN_004b3ef0 at 004b3ef0
 * undefined FUN_004b3ef0(void)
 * Address ranges: 004b3ef0-004b3f2b
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 FUN_004b3ef0(undefined4 param_1)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  
  uVar3 = param_1;
  iVar1 = (**(code **)(*DAT_006ab788 + 0x14))(DAT_006ab788,param_1,&param_1);
  if (iVar1 != 0) {
    uVar2 = FUN_004b3910(iVar1);
    FUN_004afee0(s__s__d____error_duplicating_sound_005004e4,
                 s_C__libraries_dxdraw_Sound_cpp_00500494,0x154,uVar2);
  }
  return uVar3;
}

