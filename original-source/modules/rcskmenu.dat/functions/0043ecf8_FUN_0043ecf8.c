/*
 * FUN_0043ecf8 at 0043ecf8
 * undefined __register FUN_0043ecf8(int * param_1, int param_2, int param_3, int param_4, int param_5)
 * Address ranges: 0043ecf8-0043ed8d
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0043ecf8(int *param_1,int param_2,int param_3,int param_4,int param_5)

{
  char cVar1;
  undefined4 extraout_ECX;
  undefined4 extraout_ECX_00;
  undefined4 extraout_EDX;
  undefined4 extraout_EDX_00;
  
  cVar1 = FUN_00440ac4(param_1,&param_5,&param_4);
  if ((cVar1 != '\0') &&
     ((((param_2 != param_1[0xc] || (param_3 != param_1[0xd])) || (param_5 != param_1[0xe])) ||
      (param_4 != param_1[0xf])))) {
    FUN_0043fa78((int)param_1,*(char *)((int)param_1 + 0x47),'\0');
    param_1[0xc] = param_2;
    param_1[0xd] = param_3;
    param_1[0xe] = param_5;
    param_1[0xf] = param_4;
    FUN_0043ed90((int)param_1);
    (**(code **)(*param_1 + 0x74))();
    FUN_004405f0((int)param_1,0x47,0,0);
    FUN_00403088(param_1,extraout_EDX,extraout_ECX);
    if ((*(byte *)(param_1 + 8) & 1) == 0) {
      FUN_00403088(param_1,extraout_EDX_00,extraout_ECX_00);
    }
  }
  return;
}

