/*
 * FUN_0043a734 at 0043a734
 * undefined FUN_0043a734(void)
 * Address ranges: 0043a734-0043a7e7
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0043a734(int *param_1,int param_2,int param_3)

{
  uint uVar1;
  HMENU hMenu;
  int nReserved;
  HWND hWnd;
  RECT *prcRect;
  int iStack_18;
  int iStack_14;
  
  FUN_0040ebd0(param_2,param_3,&iStack_18);
  param_1[0x12] = iStack_18;
  param_1[0x13] = iStack_14;
  FUN_0043a6a0(param_1);
  (**(code **)(*param_1 + 0x3c))(param_1,param_1);
  FUN_00438ba0(param_1[10],'\0');
  FUN_00439070(param_1[10],'\0');
  FUN_00436650((int *)param_1[10]);
  FUN_00439954(param_1);
  uVar1 = FUN_0043a6e8((int)param_1);
  uVar1 = (uint)(*(ushort *)
                  (&DAT_0047b8e8 + (uint)*(byte *)(param_1 + 0x14) * 2 + (uVar1 & 0x7f) * 6) |
                *(ushort *)(&DAT_0047b8f4 + (uint)*(byte *)(param_1 + 0x16) * 2)) |
          (uint)*(byte *)((int)param_1 + 0x59) << 10;
  prcRect = (RECT *)0x0;
  hWnd = *(HWND *)(DAT_0047d798 + 0x10);
  nReserved = 0;
  hMenu = (HMENU)FUN_00436734(param_1[10]);
  TrackPopupMenu(hMenu,uVar1,param_2,param_3,nReserved,hWnd,prcRect);
  return;
}

