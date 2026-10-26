/*
 * FUN_0041d6c0 at 0041d6c0
 * undefined FUN_0041d6c0(void)
 * Address ranges: 0041d6c0-0041d8e8
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0041d6c0(int param_1)

{
  if ((param_1 < 0) || (10 < param_1)) {
    FUN_004afee0(s__change_active_camera__illegal_c_004e2fd0,param_1,10);
  }
  switch(param_1) {
  case 0:
    DAT_00508670 = 0;
    DAT_00508674 = *(undefined4 *)(DAT_004e3068 * 0xd0 + 0x1c + DAT_0067ee20);
    DAT_00508648 = *(undefined4 *)(DAT_004e3068 * 0xd0 + 0x1c + DAT_0067ee20);
    return;
  case 1:
    DAT_00508670 = 1;
    DAT_0050864c = *(undefined4 *)(DAT_004e3068 * 0xd0 + 0x1c + DAT_0067ee20);
    return;
  default:
    DAT_00508670 = 0;
    return;
  case 3:
    DAT_00508670 = 3;
    DAT_00508674 = *(undefined4 *)(DAT_004e3068 * 0xd0 + 0x1c + DAT_0067ee20);
    _DAT_00508654 = *(undefined4 *)(DAT_004e3068 * 0xd0 + 0x1c + DAT_0067ee20);
    return;
  case 4:
    DAT_00508670 = 4;
    DAT_00508674 = *(undefined4 *)(DAT_004e3068 * 0xd0 + 0x1c + DAT_0067ee20);
    _DAT_00508658 = *(undefined4 *)(DAT_004e3068 * 0xd0 + 0x1c + DAT_0067ee20);
    return;
  case 5:
    DAT_00508670 = 5;
    DAT_00508674 = *(undefined4 *)(DAT_004e3068 * 0xd0 + 0x1c + DAT_0067ee20);
    _DAT_0050865c = *(undefined4 *)(DAT_004e3068 * 0xd0 + 0x1c + DAT_0067ee20);
    *(undefined4 *)(DAT_00680ba0 + 0x80 + DAT_00508634 * 0x178) = 0;
    return;
  case 6:
    DAT_00508670 = 6;
    DAT_00508674 = *(undefined4 *)(DAT_004e3068 * 0xd0 + 0x1c + DAT_0067ee20);
    _DAT_00508660 = *(undefined4 *)(DAT_004e3068 * 0xd0 + 0x1c + DAT_0067ee20);
    return;
  case 7:
    DAT_00508670 = 7;
    DAT_00508674 = *(undefined4 *)(DAT_004e3068 * 0xd0 + 0x1c + DAT_0067ee20);
    _DAT_00508664 = *(undefined4 *)(DAT_004e3068 * 0xd0 + 0x1c + DAT_0067ee20);
    return;
  case 8:
    DAT_00508670 = 8;
    DAT_00508674 = *(undefined4 *)(DAT_004e3068 * 0xd0 + 0x1c + DAT_0067ee20);
    _DAT_00508668 = *(undefined4 *)(DAT_004e3068 * 0xd0 + 0x1c + DAT_0067ee20);
    return;
  case 9:
    DAT_00508670 = 9;
    DAT_00508674 = *(undefined4 *)(DAT_004e3068 * 0xd0 + 0x1c + DAT_0067ee20);
    _DAT_0050866c = *(undefined4 *)(DAT_004e3068 * 0xd0 + 0x1c + DAT_0067ee20);
    return;
  }
}

