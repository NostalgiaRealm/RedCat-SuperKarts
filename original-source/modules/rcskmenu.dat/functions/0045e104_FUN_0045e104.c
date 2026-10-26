/*
 * FUN_0045e104 at 0045e104
 * undefined __register FUN_0045e104(int * param_1)
 * Address ranges: 0045e104-0045e162
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0045e104(int *param_1)

{
  int iVar1;
  
  FUN_00440fc8((int)param_1);
  *(undefined1 *)(param_1 + 0x84) = 0;
  iVar1 = *(int *)PTR_DAT_0047c86c;
  *(int *)(iVar1 + 0x108) = param_1[0x8c];
  *(int *)(iVar1 + 0x10c) = param_1[0x8d];
  param_1[0x8c] = 0;
  param_1[0x8d] = 0;
  (**(code **)(*param_1 + 0x74))();
  if (*(short *)((int)param_1 + 0x22a) != 0) {
    (*(code *)param_1[0x8a])(param_1[0x8b],param_1);
  }
  return;
}

