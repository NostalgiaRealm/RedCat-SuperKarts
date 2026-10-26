/*
 * FUN_00405380 at 00405380
 * undefined FUN_00405380(void)
 * Address ranges: 00405380-00405571
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00405380(int param_1,int param_2,undefined4 param_3)

{
  switch(param_3) {
  case 4:
    *(undefined4 *)(DAT_00504f98 + 0x18 + param_1 * 0x6c) = 0x41855c29;
    break;
  case 5:
    *(undefined4 *)(DAT_00504f98 + 0x18 + param_1 * 0x6c) = 0x41b1c28f;
    break;
  case 6:
    *(undefined4 *)(DAT_00504f98 + 0x18 + param_1 * 0x6c) = 0x420551ec;
    break;
  case 8:
    *(undefined4 *)(DAT_00504f98 + 0x18 + param_1 * 0x6c) = 0x43fa0000;
    break;
  case 10:
    if (DAT_004ecd7c == 0) {
      *(undefined4 *)(param_1 * 0x6c + 0x18 + DAT_00504f98) = 0;
      *(undefined4 *)(param_1 * 0x6c + 8 + DAT_00504f98) = 1;
    }
  }
  if (param_2 == 1) {
    switch(param_3) {
    case 0x12:
      FUN_004afce0(s_1_baans_004de1c4);
      *(undefined4 *)(DAT_00504f98 + 0x3c + param_1 * 0x6c) = 1;
      return;
    case 0x13:
      FUN_004afce0(s_2_baans_004de1d0);
      *(undefined4 *)(DAT_00504f98 + 0x3c + param_1 * 0x6c) = 2;
      return;
    case 0x14:
      FUN_004afce0(s_3_baans_004de1dc);
      *(undefined4 *)(DAT_00504f98 + 0x3c + param_1 * 0x6c) = 3;
      return;
    case 0x15:
      FUN_004afce0(s_4_baans_004de1e8);
      *(undefined4 *)(DAT_00504f98 + 0x3c + param_1 * 0x6c) = 4;
      return;
    }
  }
  else if (param_2 == 0) {
    switch(param_3) {
    case 0x28:
      FUN_004afce0(s_1_baans_004de1f4);
      *(undefined4 *)(DAT_00504f98 + 0x3c + param_1 * 0x6c) = 1;
      return;
    case 0x29:
      FUN_004afce0(s_2_baans_004de200);
      *(undefined4 *)(DAT_00504f98 + 0x3c + param_1 * 0x6c) = 2;
      return;
    case 0x2a:
      FUN_004afce0(s_3_baans_004de20c);
      *(undefined4 *)(DAT_00504f98 + 0x3c + param_1 * 0x6c) = 3;
      return;
    case 0x2b:
      FUN_004afce0(s_4_baans_004de218);
      *(undefined4 *)(DAT_00504f98 + 0x3c + param_1 * 0x6c) = 4;
    }
  }
  return;
}

