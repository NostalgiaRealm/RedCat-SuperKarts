/*
 * FUN_00407a40 at 00407a40
 * undefined FUN_00407a40(void)
 * Address ranges: 00407a40-00407b46
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

float10 FUN_00407a40(undefined4 param_1,byte param_2)

{
  switch(param_1) {
  case 4:
    if ((param_2 & 4) != 0) {
      return (float10)DAT_0050504c - (float10)5.0;
    }
    if ((param_2 & 8) != 0) {
      return (float10)DAT_0050504c + (float10)5.0;
    }
    if ((param_2 & 0x10) == 0) {
      return (float10)DAT_0050504c;
    }
    goto LAB_00407a81;
  case 5:
    if ((param_2 & 4) != 0) {
      return (float10)_DAT_00505050 - (float10)10.0;
    }
    if ((param_2 & 8) != 0) {
      return (float10)_DAT_00505050 + (float10)10.0;
    }
    break;
  case 6:
    if ((param_2 & 4) != 0) {
      return (float10)_DAT_00505054 - (float10)15.0;
    }
    if ((param_2 & 8) != 0) {
      return (float10)_DAT_00505054 + (float10)15.0;
    }
    if ((param_2 & 0x10) != 0) {
      return (float10)_DAT_00505054 + (float10)35.0;
    }
LAB_00407a81:
    return (float10)_DAT_00505054;
  default:
    if ((param_2 & 4) != 0) {
      return (float10)DAT_0050504c - (float10)5.0;
    }
    if (((param_2 & 8) == 0) && ((param_2 & 0x10) != 0)) {
      return (float10)_DAT_00505054 + (float10)20.0;
    }
    goto LAB_00407b40;
  case 8:
    if ((param_2 & 4) != 0) {
      return (float10)DAT_0050504c - (float10)5.0;
    }
    if ((param_2 & 8) != 0) goto LAB_00407b40;
  }
  if ((param_2 & 0x10) != 0) {
    return (float10)_DAT_00505054 + (float10)20.0;
  }
LAB_00407b40:
  return (float10)_DAT_00505050;
}

