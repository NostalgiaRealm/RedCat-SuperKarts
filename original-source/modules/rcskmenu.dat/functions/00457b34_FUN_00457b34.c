/*
 * FUN_00457b34 at 00457b34
 * undefined4 __register FUN_00457b34(int param_1)
 * Address ranges: 00457b34-00457b4a
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 FUN_00457b34(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = FUN_004578f0(param_1);
  uVar2 = FUN_00457a30(param_1,iVar1);
  return CONCAT31((int3)((uint)uVar2 >> 8),1);
}

