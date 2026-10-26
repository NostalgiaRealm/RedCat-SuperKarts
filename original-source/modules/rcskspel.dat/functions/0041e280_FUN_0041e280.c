/*
 * FUN_0041e280 at 0041e280
 * undefined FUN_0041e280(void)
 * Address ranges: 0041e280-0041eb08
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0041e280(undefined4 param_1)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  
  uVar1 = 0;
  DAT_004e3064 = param_1;
  switch(param_1) {
  case 0:
    FUN_00498a50(*(undefined4 *)(DAT_004e3068 * 0xd0 + 0xc + DAT_0067ee20),0,0x42480000,0xc3160000);
    FUN_0041d6c0(0);
    *(undefined4 *)(DAT_00680ba0 + 0x80 + DAT_00508620 * 0x178) = 0;
    FUN_00498b50(*(undefined4 *)(DAT_004e3068 * 0xd0 + 0xc + DAT_0067ee20),0,0x41c80000,0);
    *(undefined4 *)(DAT_004e3068 * 0xd0 + 0x3c + DAT_0067ee20) = 1;
    FUN_00498a10();
    uVar1 = 0x3dcccccd;
    uVar2 = 0x3dcccccd;
    goto LAB_0041e9bc;
  case 1:
    FUN_00498a50(*(undefined4 *)(DAT_004e3068 * 0xd0 + 0xc + DAT_0067ee20),0,0x42480000,0xc3160000);
    FUN_0041d6c0(0);
    *(undefined4 *)(DAT_00680ba0 + 0x80 + DAT_00508620 * 0x178) = 0;
    FUN_00498b50(*(undefined4 *)(DAT_004e3068 * 0xd0 + 0xc + DAT_0067ee20),0,0x42480000,0);
    *(undefined4 *)(DAT_004e3068 * 0xd0 + 0x3c + DAT_0067ee20) = 1;
    FUN_00498a10();
    uVar1 = 0x3dcccccd;
    uVar2 = 0x3dcccccd;
    goto LAB_0041e9bc;
  case 2:
    FUN_00498ad0(0,0,0xc0000000);
    FUN_0041d6c0(0);
    *(undefined4 *)(DAT_00680ba0 + 0x80 + DAT_00508620 * 0x178) = 0;
    FUN_00498b50(*(undefined4 *)(DAT_004e3068 * 0xd0 + 0xc + DAT_0067ee20),0,0,0);
    *(undefined4 *)(DAT_004e3068 * 0xd0 + 0x3c + DAT_0067ee20) = 1;
    goto LAB_0041e774;
  case 3:
    FUN_00498ad0(0,0x41780000,0xbf800000);
    FUN_0041d6c0(0);
    *(undefined4 *)(DAT_00680ba0 + 0x80 + DAT_00508620 * 0x178) = 1;
    FUN_00498bd0();
    *(undefined4 *)(DAT_004e3068 * 0xd0 + 0x3c + DAT_0067ee20) = 0;
    FUN_00498a10();
    FUN_004989d0();
    return;
  case 4:
    FUN_00498a50(*(undefined4 *)(DAT_004e3068 * 0xd0 + 0xc + DAT_0067ee20),0,0x43e10000,0xc37a0000);
    FUN_0041d6c0(0);
    *(undefined4 *)(DAT_00680ba0 + 0x80 + DAT_00508620 * 0x178) = 0;
    FUN_00498b50(*(undefined4 *)(DAT_004e3068 * 0xd0 + 0xc + DAT_0067ee20),0,0,0);
    *(undefined4 *)(DAT_004e3068 * 0xd0 + 0x3c + DAT_0067ee20) = 1;
    FUN_00498a10();
    uVar1 = 0x3e4ccccd;
    uVar2 = 0x3e99999a;
LAB_0041e9bc:
    FUN_00498950(uVar1,uVar2,0x3f000000);
    return;
  case 5:
    uVar2 = 0x41b80000;
    uVar3 = 0x42200000;
    break;
  case 6:
    uVar1 = 0xc1f00000;
    uVar2 = 0x41700000;
    uVar3 = 0x42700000;
    break;
  case 7:
    uVar1 = 0x41c80000;
    uVar2 = 0x41700000;
    uVar3 = 0xc2480000;
    break;
  case 8:
    uVar1 = 0xc1a00000;
    uVar2 = 0x41100000;
    uVar3 = 0xc1f00000;
    break;
  case 9:
    FUN_0041ebb0(0,0,0);
    return;
  case 10:
    FUN_00498ad0(0,0x42340000,0xc25c0000);
    FUN_0041d6c0(0);
    *(undefined4 *)(DAT_00680ba0 + 0x80 + DAT_00508620 * 0x178) = 0;
    FUN_00498b50(*(undefined4 *)(DAT_004e3068 * 0xd0 + 0xc + DAT_0067ee20),0,0x42480000,0);
    *(undefined4 *)(DAT_004e3068 * 0xd0 + 0x3c + DAT_0067ee20) = 1;
LAB_0041e774:
    FUN_00498990(0x3dcccccd,0x3dcccccd,0x3f000000);
    return;
  default:
    return;
  }
  FUN_00498ad0(uVar1,uVar2,uVar3);
  FUN_0041d6c0(0);
  *(undefined4 *)(DAT_00680ba0 + 0x80 + DAT_00508620 * 0x178) = 0;
  FUN_00498b50(*(undefined4 *)(DAT_004e3068 * 0xd0 + 0xc + DAT_0067ee20),0,0x42480000,0);
  *(undefined4 *)(DAT_004e3068 * 0xd0 + 0x3c + DAT_0067ee20) = 1;
  return;
}

