/*
 * FUN_004557c0 at 004557c0
 * undefined4 __register FUN_004557c0(int param_1)
 * Address ranges: 004557c0-00455804
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 FUN_004557c0(int param_1)

{
  int *piVar1;
  undefined4 uVar2;
  undefined4 extraout_ECX;
  undefined4 extraout_EDX;
  
  piVar1 = FUN_0044f4ac((int *)&PTR_FUN_0044f450,'\x01',*(undefined4 **)(param_1 + 0xc));
  (**(code **)(*piVar1 + 4))(piVar1,"lastphase",&DAT_00455810,*(undefined4 *)(param_1 + 0x14));
  FUN_00402eac(piVar1);
  piVar1 = FUN_00454f20(&DAT_00454e9c,extraout_EDX,extraout_ECX);
  uVar2 = FUN_00402eac(piVar1);
  return CONCAT31((int3)((uint)uVar2 >> 8),1);
}

