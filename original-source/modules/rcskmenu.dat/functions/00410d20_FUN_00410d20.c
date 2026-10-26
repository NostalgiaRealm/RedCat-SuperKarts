/*
 * FUN_00410d20 at 00410d20
 * undefined FUN_00410d20(void)
 * Address ranges: 00410d20-00410d67
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00410d20(int *param_1,undefined *param_2)

{
  int *piVar1;
  undefined4 *in_FS_OFFSET;
  undefined4 uStackY_18;
  undefined1 *puStackY_14;
  
  puStackY_14 = (undefined1 *)0x410d37;
  piVar1 = FUN_00411ab8((int *)&PTR_FUN_0040e4bc,'\x01',param_2,0x20);
  puStackY_14 = &LAB_00410d68;
  uStackY_18 = *in_FS_OFFSET;
  *in_FS_OFFSET = &uStackY_18;
  (**(code **)(*param_1 + 0x5c))(param_1,piVar1);
  *in_FS_OFFSET = uStackY_18;
  puStackY_14 = (undefined1 *)0x410d67;
  FUN_00402eac(piVar1);
  return;
}

