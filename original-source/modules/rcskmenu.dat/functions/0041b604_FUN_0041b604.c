/*
 * FUN_0041b604 at 0041b604
 * undefined __register FUN_0041b604(int param_1, undefined4 param_2, undefined4 param_3)
 * Address ranges: 0041b604-0041b686
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0041b604(int param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  HENHMETAFILE pHVar2;
  
  if (*(int *)(param_1 + 0x20) == 0) {
    FUN_0041b0b4(param_1);
  }
  else if (1 < *(int *)(*(int *)(param_1 + 0x20) + 4)) {
    iVar1 = FUN_00402e7c((int *)&PTR_FUN_00416690,'\x01',param_3);
    pHVar2 = *(HENHMETAFILE *)(*(int *)(param_1 + 0x20) + 8);
    if (pHVar2 != (HENHMETAFILE)0x0) {
      pHVar2 = CopyEnhMetaFileA(pHVar2,(LPCSTR)0x0);
      *(HENHMETAFILE *)(iVar1 + 8) = pHVar2;
    }
    *(undefined4 *)(iVar1 + 0x10) = *(undefined4 *)(*(int *)(param_1 + 0x20) + 0x10);
    *(undefined4 *)(iVar1 + 0xc) = *(undefined4 *)(*(int *)(param_1 + 0x20) + 0xc);
    *(undefined2 *)(iVar1 + 0x18) = *(undefined2 *)(*(int *)(param_1 + 0x20) + 0x18);
    *(undefined4 *)(iVar1 + 0x1c) = *(undefined4 *)(*(int *)(param_1 + 0x20) + 0x1c);
    *(undefined4 *)(iVar1 + 0x20) = *(undefined4 *)(*(int *)(param_1 + 0x20) + 0x20);
    FUN_0041bd54(*(int **)(param_1 + 0x20));
    *(int *)(param_1 + 0x20) = iVar1;
    FUN_0041bd50(iVar1);
  }
  return;
}

