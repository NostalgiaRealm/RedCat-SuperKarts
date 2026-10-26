/*
 * FUN_004560b4 at 004560b4
 * undefined __register FUN_004560b4(int param_1, undefined * param_2)
 * Address ranges: 004560b4-00456129
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_004560b4(int param_1,undefined *param_2)

{
  int *piVar1;
  undefined4 uVar2;
  int extraout_ECX;
  undefined4 *in_FS_OFFSET;
  undefined4 uStackY_28;
  undefined1 *puStackY_24;
  undefined4 uStack_1c;
  undefined1 *puStack_18;
  undefined1 *puStack_14;
  
  puStack_14 = (undefined1 *)0x4560c8;
  FUN_00403f84((int)param_2);
  puStack_18 = &LAB_00456147;
  uStack_1c = *in_FS_OFFSET;
  *in_FS_OFFSET = &uStack_1c;
  puStack_14 = &stack0xfffffffc;
  FUN_00455fb8(param_1);
  puStackY_24 = (undefined1 *)0x4560ee;
  piVar1 = FUN_00411ab8((int *)&PTR_FUN_0040e4bc,'\x01',param_2,0);
  puStackY_24 = &LAB_0045612a;
  uStackY_28 = *in_FS_OFFSET;
  *in_FS_OFFSET = &uStackY_28;
  uVar2 = FUN_004118b0(piVar1);
  *(undefined4 *)(param_1 + 0x2c) = uVar2;
  FUN_00455fe4(param_1,piVar1,extraout_ECX);
  *in_FS_OFFSET = uStackY_28;
  puStackY_24 = (undefined1 *)0x456129;
  FUN_00402eac(piVar1);
  return;
}

