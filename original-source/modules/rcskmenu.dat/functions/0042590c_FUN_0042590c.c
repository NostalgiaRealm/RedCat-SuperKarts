/*
 * FUN_0042590c at 0042590c
 * undefined __register FUN_0042590c(int * param_1, int param_2)
 * Address ranges: 0042590c-00425974
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0042590c(int *param_1,int param_2)

{
  byte bVar1;
  char cVar2;
  undefined4 extraout_ECX;
  undefined4 extraout_ECX_00;
  uint extraout_EDX;
  undefined4 extraout_EDX_00;
  
  if (((*(short *)(param_2 + 4) == 0xd) && (*(char *)((int)param_1 + 0x1fa) != '\0')) ||
     ((*(short *)(param_2 + 4) == 0x1b && (*(char *)((int)param_1 + 0x1f9) != '\0')))) {
    bVar1 = FUN_004297c4(*(uint *)(param_2 + 8));
    if ((bVar1 == 0) &&
       (cVar2 = FUN_00403088(param_1,extraout_EDX & 0xffffff00,extraout_ECX), cVar2 != '\0')) {
      FUN_00403088(param_1,extraout_EDX_00,extraout_ECX_00);
      *(undefined4 *)(param_2 + 0xc) = 1;
      return;
    }
  }
  FUN_00444c44((int)param_1,param_2);
  return;
}

