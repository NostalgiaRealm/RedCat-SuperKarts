/*
 * FUN_0043d668 at 0043d668
 * int * __register FUN_0043d668(POINT * param_1, int * param_2, char param_3, int * param_4)
 * Address ranges: 0043d668-0043d6b4
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

int * FUN_0043d668(POINT *param_1,int *param_2,char param_3,int *param_4)

{
  HWND pHVar1;
  int *piVar2;
  int iVar3;
  undefined4 extraout_EDX;
  
  if (param_3 == '\0') {
    pHVar1 = FUN_0043d63c(param_1);
    *param_2 = (int)pHVar1;
    piVar2 = (int *)FUN_0043d5c0((HWND)*param_2,CONCAT31((int3)((uint)extraout_EDX >> 8),5),
                                 DAT_0047d7bc,&param_1->x,0);
  }
  else {
    piVar2 = FUN_0043d414(&param_1->x,param_4);
    if (piVar2 != (int *)0x0) {
      iVar3 = FUN_00445724(piVar2);
      *param_2 = iVar3;
    }
  }
  return piVar2;
}

