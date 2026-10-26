/*
 * FUN_00418724 at 00418724
 * undefined __register FUN_00418724(int * param_1, int param_2, int param_3, undefined * param_4)
 * Address ranges: 00418724-004187ab
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00418724(int *param_1,int param_2,int param_3,undefined *param_4)

{
  undefined4 uVar1;
  LONG LVar2;
  UINT c;
  LPCSTR lpString;
  INT *lpDx;
  
  (**(code **)(*param_1 + 0x10))();
  FUN_00418a68(param_1,0xb);
  uVar1 = FUN_004186f8(param_1);
  if ((char)uVar1 == '\x01') {
    LVar2 = FUN_004187f4(param_1,param_4);
    param_2 = param_2 + LVar2 + 1;
  }
  lpDx = (INT *)0x0;
  c = FUN_00403dd0((int)param_4);
  lpString = FUN_00403f94(param_4);
  ExtTextOutA((HDC)param_1[1],param_2,param_3,param_1[0x15],(RECT *)0x0,lpString,c,lpDx);
  LVar2 = FUN_004187f4(param_1,param_4);
  FUN_00418610(param_1,LVar2 + param_2,param_3);
  (**(code **)(*param_1 + 0xc))();
  return;
}

