/*
 * FUN_00433a14 at 00433a14
 * undefined __register FUN_00433a14(int * param_1)
 * Address ranges: 00433a14-00433a46
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00433a14(int *param_1)

{
  bool bVar1;
  HIMAGELIST himl;
  undefined4 extraout_ECX;
  undefined4 extraout_ECX_00;
  undefined4 uVar2;
  undefined4 extraout_EDX;
  undefined4 extraout_EDX_00;
  undefined4 uVar3;
  
  bVar1 = FUN_00433874((int)param_1);
  uVar2 = extraout_ECX;
  uVar3 = extraout_EDX;
  if ((bVar1) && (*(char *)((int)param_1 + 0x36) == '\0')) {
    himl = (HIMAGELIST)FUN_004339b0(param_1);
    ImageList_Destroy(himl);
    uVar2 = extraout_ECX_00;
    uVar3 = extraout_EDX_00;
  }
  param_1[0xc] = 0;
  FUN_00403088(param_1,uVar3,uVar2);
  return;
}

