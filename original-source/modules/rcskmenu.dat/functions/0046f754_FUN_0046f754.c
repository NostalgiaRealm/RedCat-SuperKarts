/*
 * FUN_0046f754 at 0046f754
 * undefined1 __register FUN_0046f754(int * param_1)
 * Address ranges: 0046f754-0046f78e;0046f7a7-0046f7b5
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined1 FUN_0046f754(int *param_1)

{
  undefined4 *in_FS_OFFSET;
  undefined4 uStack_20;
  undefined1 *puStack_1c;
  undefined1 *puStack_18;
  
  puStack_18 = &stack0xfffffffc;
  puStack_1c = &LAB_0046f78f;
  uStack_20 = *in_FS_OFFSET;
  *in_FS_OFFSET = &uStack_20;
  (**(code **)(*param_1 + 0xd8))();
  *(undefined1 *)(*(int *)(*(int *)PTR_DAT_0047c670 + 0x7c) + 0x11) = 2;
  *in_FS_OFFSET = uStack_20;
  return (char)param_1[0xb5];
}

