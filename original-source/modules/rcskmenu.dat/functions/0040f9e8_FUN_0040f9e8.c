/*
 * FUN_0040f9e8 at 0040f9e8
 * undefined __register FUN_0040f9e8(int param_1, int param_2)
 * Address ranges: 0040f9e8-0040fa63
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0040f9e8(int param_1,int param_2)

{
  int iVar1;
  undefined4 *in_FS_OFFSET;
  undefined4 uStack_18;
  undefined1 *puStack_14;
  undefined1 *puStack_10;
  
  puStack_10 = (undefined1 *)0x40f9fa;
  FUN_0040fa70(param_1);
  puStack_14 = &LAB_0040fa64;
  uStack_18 = *in_FS_OFFSET;
  *in_FS_OFFSET = &uStack_18;
  puStack_10 = &stack0xfffffffc;
  if (*(char *)(param_1 + 0x20) != '\x01') {
    puStack_10 = &stack0xfffffffc;
    iVar1 = FUN_0040f70c(*(int *)(param_1 + 4),param_2);
    if (iVar1 != -1) {
      if (*(char *)(param_1 + 0x20) == '\x02') {
        FUN_0040f5ec(**(undefined4 **)(param_1 + 4),(undefined4 *)PTR_PTR_0047c780,param_2);
      }
      goto LAB_0040fa4e;
    }
  }
  FUN_0040f504(*(int **)(param_1 + 4),param_2);
LAB_0040fa4e:
  *in_FS_OFFSET = uStack_18;
  puStack_10 = &LAB_0040fa6b;
  puStack_14 = (undefined1 *)0x40fa63;
  FUN_0040fad4(param_1);
  return;
}

