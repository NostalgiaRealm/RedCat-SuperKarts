/*
 * FUN_0041b798 at 0041b798
 * undefined __register FUN_0041b798(int param_1, int * param_2)
 * Address ranges: 0041b798-0041b8b2;0041b8da-0041b8df
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0041b798(int param_1,int *param_2)

{
  int iVar1;
  int iVar2;
  UINT UVar3;
  undefined4 *in_FS_OFFSET;
  undefined4 uVar4;
  ushort local_26 [5];
  undefined2 local_1c;
  undefined2 local_1a;
  ushort local_18;
  ushort local_12;
  HDC local_10;
  UINT local_c;
  LPBYTE local_8;
  
  if (*(int *)(param_1 + 0x20) == 0) {
    return;
  }
  FUN_00402b54((undefined4 *)local_26,0x16,0);
  iVar1 = *(int *)(param_1 + 0x20);
  local_26[0] = 0xcdd7;
  local_26[1] = 0x9ac6;
  local_18 = *(ushort *)(iVar1 + 0x18);
  if (local_18 == 0) {
    local_18 = 0x60;
  }
  iVar2 = MulDiv(*(int *)(iVar1 + 0xc),(uint)local_18,0x9ec);
  local_1c = (undefined2)iVar2;
  iVar2 = MulDiv(*(int *)(iVar1 + 0x10),(uint)local_18,0x9ec);
  local_1a = (undefined2)iVar2;
  local_12 = FUN_00419ad4(local_26);
  local_10 = GetDC((HWND)0x0);
  *in_FS_OFFSET = &stack0xffffffc4;
  local_c = GetWinMetaFileBits(*(HENHMETAFILE *)(iVar1 + 8),0,(LPBYTE)0x0,8,local_10);
  local_8 = (LPBYTE)FUN_00402714(local_c);
  uVar4 = *in_FS_OFFSET;
  *in_FS_OFFSET = &stack0xffffffb8;
  UVar3 = GetWinMetaFileBits(*(HENHMETAFILE *)(iVar1 + 8),local_c,local_8,8,local_10);
  if (UVar3 < local_c) {
    FUN_00418ce4();
  }
  FUN_00411920(param_2,local_26,0x16);
  FUN_00411920(param_2,local_8,local_c);
  *in_FS_OFFSET = uVar4;
  FUN_0040272c((int)local_8);
  return;
}

