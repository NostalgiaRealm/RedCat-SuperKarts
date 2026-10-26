/*
 * FUN_0045fb80 at 0045fb80
 * undefined FUN_0045fb80(void)
 * Address ranges: 0045fb80-0045fba7;0045fbc8-0045fc21
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0045fb80(int *param_1,undefined2 *param_2,undefined4 param_3)

{
  FUN_004443a8((int)param_1,param_2,param_3);
  switch(*param_2) {
  case 0x21:
    FUN_0045fa4c(param_1,param_1[0x7e]);
    break;
  case 0x22:
    FUN_0045fa00(param_1,param_1[0x7e]);
    break;
  case 0x23:
    FUN_0045fd98(param_1,param_1[0x7f]);
    break;
  case 0x24:
    FUN_0045fd98(param_1,param_1[0x80]);
    break;
  case 0x25:
  case 0x28:
    FUN_0045fa00(param_1,1);
    break;
  case 0x26:
  case 0x27:
    FUN_0045fa4c(param_1,1);
  }
  return;
}

