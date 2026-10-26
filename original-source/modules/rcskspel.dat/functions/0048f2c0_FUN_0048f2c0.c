/*
 * FUN_0048f2c0 at 0048f2c0
 * undefined FUN_0048f2c0(void)
 * Address ranges: 0048f2c0-0048f3d7
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __fastcall FUN_0048f2c0(BOOL *param_1)

{
  BOOL BVar1;
  int iVar2;
  int iVar3;
  LARGE_INTEGER local_8;
  
  BVar1 = QueryPerformanceFrequency(&local_8);
  *param_1 = BVar1;
  if (BVar1 == 0) {
    param_1[1] = 0x447a0000;
  }
  else {
    param_1[1] = (BOOL)(float)(longlong)local_8;
  }
  if (DAT_0067ec34 != 0) {
    if (DAT_0067ec34 == 1) {
      FUN_004afce0(s_T_ARRAY___deleting___16_16s___16_004de718,&DAT_0067ec55,&DAT_0067ec3c,
                   DAT_0067ec2c);
      FUN_004bc150(DAT_0067ec28);
    }
    if (DAT_0067ec34 != 0) {
      FUN_004bc150(DAT_0067ec38);
      DAT_0067ec34 = 0;
    }
    FUN_004afce0(s___done_deleting_T_ARRAY_004de6fc);
  }
  DAT_0067ec28 = operator_new(0x10);
  DAT_0067ec2c = 4;
  _DAT_0067ec30 = 0;
  DAT_0067ec38 = operator_new(4);
  FUN_004afce0(s_T_ARRAY___alloc___16_16s___16_16_004de744,&DAT_0067ec55,&DAT_0067ec3c,DAT_0067ec2c)
  ;
  DAT_0067ec34 = 1;
  iVar3 = 0;
  do {
    iVar2 = iVar3 + 1;
    *(undefined1 *)((int)DAT_0067ec38 + iVar3) = 1;
    iVar3 = iVar2;
  } while (iVar2 < 4);
  iVar3 = 0;
  do {
    iVar2 = iVar3 + 4;
    *(undefined4 *)(iVar3 + (int)DAT_0067ec28) = 0x3dcccccd;
    iVar3 = iVar2;
  } while (iVar2 < 0x10);
  FUN_0048f3e0();
  return;
}

