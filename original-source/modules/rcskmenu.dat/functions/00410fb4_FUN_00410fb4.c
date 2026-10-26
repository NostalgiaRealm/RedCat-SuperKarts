/*
 * FUN_00410fb4 at 00410fb4
 * undefined __register FUN_00410fb4(int * param_1, undefined * param_2)
 * Address ranges: 00410fb4-00410ffe
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00410fb4(int *param_1,undefined *param_2)

{
  int *piVar1;
  undefined4 *in_FS_OFFSET;
  undefined4 uStackY_18;
  undefined1 *puStackY_14;
  
  puStackY_14 = (undefined1 *)0x410fce;
  piVar1 = FUN_00411ab8((int *)&PTR_FUN_0040e4bc,'\x01',param_2,0xffff);
  puStackY_14 = &LAB_00410fff;
  uStackY_18 = *in_FS_OFFSET;
  *in_FS_OFFSET = &uStackY_18;
  (**(code **)(*param_1 + 0x68))(param_1,piVar1);
  *in_FS_OFFSET = uStackY_18;
  puStackY_14 = (undefined1 *)0x410ffe;
  FUN_00402eac(piVar1);
  return;
}

