/*
 * FUN_0041e1c0 at 0041e1c0
 * undefined __register FUN_0041e1c0(int param_1)
 * Address ranges: 0041e1c0-0041e235
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0041e1c0(int param_1)

{
  int iVar1;
  undefined4 uStack_18;
  undefined1 auStack_14 [2];
  short local_12;
  ushort local_10;
  undefined1 local_c [4];
  
  iVar1 = *(int *)(param_1 + 0x20);
  if ((*(int *)(iVar1 + 8) == 0) && (*(int **)(iVar1 + 0xc) != (int *)0x0)) {
    FUN_004118a4(*(int **)(iVar1 + 0xc),0);
    uStack_18 = 0x41e1ed;
    FUN_004118e8(*(int **)(iVar1 + 0xc),auStack_14,6);
    if (local_12 != 0) {
      if (local_12 == 1) {
        uStack_18 = 6;
        FUN_004197cc(*(int **)(iVar1 + 0xc),local_c,(uint)local_10,(int *)(iVar1 + 0x10),
                     (int *)(param_1 + 0x24));
      }
      else {
        uStack_18 = 0x41e229;
        FUN_00418c78();
      }
    }
    *(undefined4 *)(iVar1 + 8) = uStack_18;
  }
  return;
}

