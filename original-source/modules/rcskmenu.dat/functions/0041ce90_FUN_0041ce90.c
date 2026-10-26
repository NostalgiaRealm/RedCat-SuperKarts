/*
 * FUN_0041ce90 at 0041ce90
 * undefined __register FUN_0041ce90(int param_1)
 * Address ranges: 0041ce90-0041cf02
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0041ce90(int param_1)

{
  int iVar1;
  HPALETTE pHVar2;
  
  iVar1 = *(int *)(param_1 + 0x20);
  if ((*(int *)(iVar1 + 8) != 0) && (*(int *)(iVar1 + 0x14) == 0)) {
    FUN_0041d064(param_1);
    if (*(int *)(iVar1 + 0x30) == 0) {
      GetObjectA(*(HANDLE *)(iVar1 + 8),0x54,(LPVOID)(iVar1 + 0x18));
      *(undefined4 *)(iVar1 + 0x30) = 0x28;
      *(undefined4 *)(iVar1 + 0x34) = *(undefined4 *)(iVar1 + 0x1c);
      *(undefined4 *)(iVar1 + 0x38) = *(undefined4 *)(iVar1 + 0x20);
      *(undefined2 *)(iVar1 + 0x3c) = 1;
      *(short *)(iVar1 + 0x3e) = *(short *)(iVar1 + 0x28) * *(short *)(iVar1 + 0x2a);
    }
    pHVar2 = FUN_0041bf24(*(HBITMAP *)(iVar1 + 8),*(HPALETTE *)(iVar1 + 0x10),
                          *(HPALETTE *)(iVar1 + 0x10),0,iVar1 + 0x18);
    *(HPALETTE *)(iVar1 + 0x14) = pHVar2;
  }
  return;
}

