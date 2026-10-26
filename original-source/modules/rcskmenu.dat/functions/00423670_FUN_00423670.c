/*
 * FUN_00423670 at 00423670
 * undefined __register FUN_00423670(int * param_1)
 * Address ranges: 00423670-00423739
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00423670(int *param_1)

{
  char cVar1;
  HDC hDC;
  undefined4 extraout_ECX;
  undefined4 extraout_EDX;
  int iVar2;
  char acStack_20 [4];
  undefined1 local_1c [8];
  int iStack_14;
  undefined4 uStack_10;
  
  if (((*(byte *)(param_1 + 8) & 2) == 0) && (*(char *)((int)param_1 + 0x12d) != '\0')) {
    (**(code **)(*param_1 + 0x40))(param_1,local_1c);
    hDC = GetDC((HWND)0x0);
    FUN_00418a14((int *)param_1[0x48],(int)hDC);
    FUN_00403088(param_1,local_1c,
                 (uint)(*(ushort *)(&DAT_0047b640 + (uint)*(byte *)((int)param_1 + 0x12f) * 2) |
                       0x440));
    FUN_00418a14((int *)param_1[0x48],0);
    ReleaseDC((HWND)0x0,hDC);
    iVar2 = param_1[0xc];
    acStack_20[0] = (char)param_1[0x4b];
    cVar1 = FUN_00403088(param_1,extraout_EDX,extraout_ECX);
    if (cVar1 != '\0') {
      FUN_0043c798(acStack_20);
    }
    if (acStack_20[0] == '\x01') {
      iVar2 = iVar2 + (param_1[0xe] - iStack_14);
    }
    (**(code **)(*param_1 + 0x7c))(param_1,iVar2,param_1[0xd],uStack_10,iStack_14);
  }
  return;
}

