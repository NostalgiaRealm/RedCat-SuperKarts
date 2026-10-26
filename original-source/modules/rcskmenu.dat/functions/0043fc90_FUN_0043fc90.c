/*
 * FUN_0043fc90 at 0043fc90
 * undefined __register FUN_0043fc90(int * param_1, char param_2, int param_3)
 * Address ranges: 0043fc90-0043fd51
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0043fc90(int *param_1,char param_2,int param_3)

{
  undefined4 uVar1;
  int *piVar2;
  tagPOINT tStack_1c;
  LONG LStack_14;
  LONG LStack_10;
  
  uVar1 = FUN_00403024(param_1,(int)&PTR_FUN_00427e2c);
  if (((char)uVar1 != '\0') && (*(char *)((int)param_1 + 0x8b) != '\x01')) {
    piVar2 = FUN_0040ad20((int *)&DAT_0040de0c,'\x01',(undefined4 *)PTR_PTR_0047c89c);
    FUN_00403604(piVar2);
  }
  FUN_00440624(param_1);
  if ((DAT_0047d7b8 == 0) || (DAT_0047d7b8 == -1)) {
    DAT_0047d7b8 = 0;
    if ((*(byte *)(param_1 + 0x11) & 1) != 0) {
      GetCursorPos(&tStack_1c);
      FUN_0043f1f0(param_1,&tStack_1c.x,&LStack_14);
      tStack_1c.x = LStack_14;
      tStack_1c.y = LStack_10;
      uVar1 = FUN_00406c34((undefined2 *)&tStack_1c);
      FUN_004405f0((int)param_1,0x202,0,uVar1);
    }
    if (param_3 < 0) {
      param_3 = *(int *)(DAT_0047d7a8 + 8);
    }
    if (DAT_0047d7b8 != -1) {
      FUN_0043dbcc(param_1,param_2,param_3);
    }
  }
  return;
}

