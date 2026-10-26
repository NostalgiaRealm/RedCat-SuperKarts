/*
 * FUN_004c1835 at 004c1835
 * undefined FUN_004c1835(void)
 * Address ranges: 004c1835-004c188e
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_004c1835(char *param_1)

{
  char cVar1;
  char cVar2;
  int iVar3;
  uint uVar4;
  
  iVar3 = FUN_004beeb6((int)*param_1);
  if (iVar3 != 0x65) {
    do {
      param_1 = param_1 + 1;
      if (DAT_00502f8c < 2) {
        uVar4 = (byte)PTR_DAT_00502d80[*param_1 * 2] & 4;
      }
      else {
        uVar4 = FUN_004c3680((int)*param_1,4);
      }
    } while (uVar4 != 0);
  }
  cVar2 = *param_1;
  *param_1 = DAT_00502f90;
  do {
    param_1 = param_1 + 1;
    cVar1 = *param_1;
    *param_1 = cVar2;
    cVar2 = cVar1;
  } while (*param_1 != '\0');
  return;
}

