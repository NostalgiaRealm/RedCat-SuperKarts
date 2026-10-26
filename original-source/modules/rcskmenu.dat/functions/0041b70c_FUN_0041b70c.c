/*
 * FUN_0041b70c at 0041b70c
 * undefined __register FUN_0041b70c(int param_1, int * param_2)
 * Address ranges: 0041b70c-0041b787;0041b78f-0041b794
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0041b70c(int param_1,int *param_2)

{
  UINT nSize;
  LPBYTE lpData;
  undefined4 *in_FS_OFFSET;
  undefined4 uVar1;
  
  if (*(int *)(param_1 + 0x20) != 0) {
    nSize = GetEnhMetaFileBits(*(HENHMETAFILE *)(*(int *)(param_1 + 0x20) + 8),0,(LPBYTE)0x0);
    if (nSize != 0) {
      lpData = (LPBYTE)FUN_00402714(nSize);
      uVar1 = *in_FS_OFFSET;
      *in_FS_OFFSET = &stack0xffffffe0;
      GetEnhMetaFileBits(*(HENHMETAFILE *)(*(int *)(param_1 + 0x20) + 8),nSize,lpData);
      FUN_00411920(param_2,lpData,nSize);
      *in_FS_OFFSET = uVar1;
      FUN_0040272c((int)lpData);
      return;
    }
  }
  return;
}

