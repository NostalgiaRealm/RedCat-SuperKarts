/*
 * FUN_0041b964 at 0041b964
 * undefined __register FUN_0041b964(int param_1, undefined2 * param_2, undefined4 * param_3, undefined4 * param_4)
 * Address ranges: 0041b964-0041b994
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0041b964(int param_1,undefined2 *param_2,undefined4 *param_3,undefined4 *param_4)

{
  int iVar1;
  HENHMETAFILE pHVar2;
  
  iVar1 = *(int *)(param_1 + 0x20);
  if (iVar1 != 0) {
    *param_2 = 0xe;
    *param_4 = 0;
    pHVar2 = CopyEnhMetaFileA(*(HENHMETAFILE *)(iVar1 + 8),(LPCSTR)0x0);
    *param_3 = pHVar2;
  }
  return;
}

