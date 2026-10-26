/*
 * FUN_0041a14c at 0041a14c
 * undefined FUN_0041a14c(void)
 * Address ranges: 0041a14c-0041a193
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0041a14c(int *param_1,undefined *param_2)

{
  int *piVar1;
  undefined4 *in_FS_OFFSET;
  undefined4 uStackY_18;
  undefined1 *puStackY_14;
  
  puStackY_14 = (undefined1 *)0x41a163;
  piVar1 = FUN_00411ab8((int *)&PTR_FUN_0040e4bc,'\x01',param_2,0x20);
  puStackY_14 = &LAB_0041a194;
  uStackY_18 = *in_FS_OFFSET;
  *in_FS_OFFSET = &uStackY_18;
  (**(code **)(*param_1 + 0x50))(param_1,piVar1);
  *in_FS_OFFSET = uStackY_18;
  puStackY_14 = (undefined1 *)0x41a193;
  FUN_00402eac(piVar1);
  return;
}

