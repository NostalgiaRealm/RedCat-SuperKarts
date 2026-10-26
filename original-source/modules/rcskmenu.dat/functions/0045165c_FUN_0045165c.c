/*
 * FUN_0045165c at 0045165c
 * undefined __register FUN_0045165c(int param_1, undefined4 * param_2)
 * Address ranges: 0045165c-004516b7
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0045165c(int param_1,undefined4 *param_2)

{
  int iVar1;
  undefined4 *puVar2;
  
  puVar2 = (undefined4 *)(param_1 + 0x15);
  for (iVar1 = 0x100; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = *param_2;
    param_2 = param_2 + 1;
    puVar2 = puVar2 + 1;
  }
  *(undefined1 *)(param_1 + 0x14) = 1;
  if ((0 < *(int *)(param_1 + 0x474)) && (0 < *(int *)(param_1 + 0x43c))) {
    SetDIBColorTable(*(HDC *)(param_1 + 0x420),0,0x100,(RGBQUAD *)(param_1 + 0x15));
    FUN_0040282c((undefined4 *)(param_1 + 0x15),
                 (undefined4 *)(*(int *)(param_1 + 0xc) + *(int *)(param_1 + 0x418)),
                 *(int *)(param_1 + 0x43c) << 2);
  }
  return;
}

