/*
 * FUN_0042eb18 at 0042eb18
 * undefined __register FUN_0042eb18(int * param_1, undefined4 param_2, int param_3)
 * Address ranges: 0042eb18-0042ebb8
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0042eb18(int *param_1,undefined4 param_2,int param_3)

{
  char cVar1;
  undefined4 extraout_ECX;
  undefined4 extraout_ECX_00;
  undefined4 extraout_EDX;
  int iStack_c;
  
  if ((*(byte *)(param_1 + 0xb3) & 8) == 0) {
    iStack_c = param_3;
    cVar1 = (**(code **)(*param_1 + 0xd0))();
    if (cVar1 != '\0') {
      if (*(char *)((int)param_1 + 0x217) == '\x01') {
        if ((*(byte *)(param_1 + 0x84) & 2) == 0) {
          iStack_c = (uint)iStack_c._1_3_ << 8;
        }
        else {
          iStack_c = CONCAT31(iStack_c._1_3_,3);
        }
      }
      else {
        iStack_c = CONCAT31(iStack_c._1_3_,1);
      }
      FUN_00403088(param_1,&iStack_c,extraout_ECX);
      if ((char)iStack_c != '\0') {
        if (param_1 == *(int **)(DAT_0047d770 + 0x38)) {
          FUN_00432448();
        }
        else if ((char)iStack_c == '\x01') {
          FUN_0042ecc8(param_1,extraout_EDX,extraout_ECX_00);
        }
        else if ((char)iStack_c == '\x03') {
          FUN_0042ca2c(param_1,1);
        }
        else {
          FUN_0042ed64(param_1);
        }
      }
    }
  }
  else {
    param_1[0x8d] = 2;
  }
  return;
}

