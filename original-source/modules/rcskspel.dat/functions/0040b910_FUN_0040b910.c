/*
 * FUN_0040b910 at 0040b910
 * undefined FUN_0040b910(void)
 * Address ranges: 0040b910-0040b9b8
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

char FUN_0040b910(int param_1)

{
  char cVar1;
  undefined4 uVar2;
  
  cVar1 = '\0';
  uVar2 = FUN_0040c970();
  switch(uVar2) {
  case 0:
  case 1:
    cVar1 = FUN_00412390(param_1,&DAT_00503ef0 + param_1 * 0x47);
    break;
  case 2:
    cVar1 = FUN_0040b9e0(param_1);
    break;
  default:
    goto switchD_0040b934_caseD_3;
  case 4:
    cVar1 = FUN_00412280(param_1,&DAT_00503ef0 + param_1 * 0x47);
    break;
  case 5:
    cVar1 = FUN_0040baa0(param_1);
    break;
  case 6:
    cVar1 = FUN_00412560(param_1,&DAT_00503ef0 + param_1 * 0x47);
  }
  if (cVar1 == '\0') {
switchD_0040b934_caseD_3:
    if ((param_1 < DAT_00508610) && (-1 < param_1)) {
      (&DAT_00508214)[param_1 * 0x70] = 0;
      return cVar1;
    }
    DAT_0053bec4 = 0;
  }
  return cVar1;
}

