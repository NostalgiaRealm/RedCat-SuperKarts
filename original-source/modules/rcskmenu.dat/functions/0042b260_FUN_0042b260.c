/*
 * FUN_0042b260 at 0042b260
 * undefined __register FUN_0042b260(int * param_1, undefined4 param_2, undefined1 * param_3)
 * Address ranges: 0042b260-0042b2a0;0042b2b8-0042b2d3
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0042b260(int *param_1,undefined4 param_2,undefined1 *param_3)

{
  undefined4 *in_FS_OFFSET;
  undefined4 uStack_20;
  undefined1 *puStack_1c;
  undefined1 *puStack_18;
  
  puStack_18 = &stack0xfffffffc;
  if (*(short *)((int)param_1 + 0x2ba) != 0) {
    puStack_1c = &LAB_0042b2a1;
    uStack_20 = *in_FS_OFFSET;
    *in_FS_OFFSET = &uStack_20;
    (*(code *)param_1[0xae])(param_1[0xaf],param_1);
    *in_FS_OFFSET = uStack_20;
    param_3 = puStack_18;
    param_2 = uStack_20;
  }
  if ((*(byte *)(param_1 + 0xb3) & 2) != 0) {
    puStack_18 = (undefined1 *)0x42b2ce;
    FUN_0042bbb8(param_1,CONCAT31((int3)((uint)param_2 >> 8),1),param_3);
  }
  return;
}

