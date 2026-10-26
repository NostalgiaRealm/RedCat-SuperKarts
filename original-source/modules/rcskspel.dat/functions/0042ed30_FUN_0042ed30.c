/*
 * FUN_0042ed30 at 0042ed30
 * undefined FUN_0042ed30(void)
 * Address ranges: 0042ed30-0042ee42
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0042ed30(undefined4 param_1)

{
  if (DAT_0053a5e8 == 0) {
    FUN_004afee0(s__set_input_devices__input_module_004eabc4);
  }
  switch(param_1) {
  case 1:
    DAT_0053a5d8 = 1;
    DAT_0053a5dc = 1;
    return;
  case 2:
    DAT_0053a5d8 = 2;
    DAT_0053a5dc = 2;
    FUN_004bab80(1,0,DAT_0053a5b8);
    FUN_004bab80(1,1,DAT_0053a5bc);
    FUN_004bab80(1,2,DAT_0053a5c0);
    FUN_004bab80(1,3,DAT_0053a5c4);
    FUN_004bab80(1,4,DAT_0053a5c8);
    FUN_004bab80(1,5,DAT_0053a5cc);
    FUN_004bab80(1,6,DAT_0053a5d0);
    FUN_004bab80(1,7,DAT_0053a5d4);
    return;
  case 3:
    DAT_0053a5d8 = 3;
    DAT_0053a5dc = 2;
    return;
  case 4:
    DAT_0053a5d8 = 4;
    DAT_0053a5dc = 2;
    return;
  default:
    FUN_004afee0(s__set_input_devices__invalid_devi_004eac0c,param_1);
    return;
  }
}

