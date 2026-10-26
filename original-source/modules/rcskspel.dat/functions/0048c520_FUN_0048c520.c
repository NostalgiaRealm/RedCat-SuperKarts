/*
 * FUN_0048c520 at 0048c520
 * undefined FUN_0048c520(void)
 * Address ranges: 0048c520-0048c7d2
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0048c520(void)

{
  int iVar1;
  undefined *puVar2;
  undefined *puVar3;
  
  if (DAT_0067e4cc == '\0') {
    puVar2 = &DAT_0067df70;
    do {
      FUN_004a16d0(puVar2,&DAT_006a5c90);
      puVar2 = puVar2 + 0x40;
    } while ((int)puVar2 < 0x67e470);
    _DAT_0067df70 = 0x3f99999a;
    _DAT_0067df84 = 0x3f99999a;
    _DAT_0067df98 = 0x3f99999a;
    _DAT_0067dfb0 = 0x3fb33333;
    _DAT_0067dfc4 = 0x3fb33333;
    _DAT_0067dfd8 = 0x3fb33333;
    _DAT_0067dff0 = 0x3f99999a;
    _DAT_0067e004 = 0x3f99999a;
    _DAT_0067e018 = 0x3f99999a;
    _DAT_0067e030 = 0x3f800000;
    _DAT_0067e044 = 0x3f800000;
    _DAT_0067e058 = 0x3f800000;
    _DAT_0067e070 = 0x3f666666;
    _DAT_0067e084 = 0x3f666666;
    _DAT_0067e098 = 0x3f666666;
    _DAT_0067e0b0 = 0x3f59999a;
    _DAT_0067e0c4 = 0x3f59999a;
    _DAT_0067e0d8 = 0x3f59999a;
    _DAT_0067e0f0 = 0x3f4ccccd;
    _DAT_0067e104 = 0x3f4ccccd;
    _DAT_0067e118 = 0x3f4ccccd;
    _DAT_0067e130 = 0x3f333333;
    _DAT_0067e144 = 0x3f333333;
    _DAT_0067e158 = 0x3f333333;
    _DAT_0067e170 = 0x3f266666;
    _DAT_0067e184 = 0x3f266666;
    _DAT_0067e198 = 0x3f266666;
    _DAT_0067e1b0 = 0x3f19999a;
    _DAT_0067e1c4 = 0x3f19999a;
    _DAT_0067e1d8 = 0x3f19999a;
    _DAT_0067e1f0 = 0x3f0ccccd;
    _DAT_0067e204 = 0x3f0ccccd;
    _DAT_0067e218 = 0x3f0ccccd;
    _DAT_0067e230 = 0x3f000000;
    _DAT_0067e244 = 0x3f000000;
    _DAT_0067e258 = 0x3f000000;
    _DAT_0067e270 = 0x3ee66666;
    _DAT_0067e284 = 0x3ee66666;
    _DAT_0067e298 = 0x3ee66666;
    _DAT_0067e2b0 = 0x3ecccccd;
    _DAT_0067e2c4 = 0x3ecccccd;
    _DAT_0067e2d8 = 0x3ecccccd;
    _DAT_0067e2f0 = 0x3eb33333;
    _DAT_0067e304 = 0x3eb33333;
    _DAT_0067e318 = 0x3eb33333;
    _DAT_0067e330 = 0x3e99999a;
    _DAT_0067e344 = 0x3e99999a;
    _DAT_0067e358 = 0x3e99999a;
    _DAT_0067e370 = 0x3e800000;
    _DAT_0067e384 = 0x3e800000;
    _DAT_0067e398 = 0x3e800000;
    _DAT_0067e3b0 = 0x3e4ccccd;
    _DAT_0067e3c4 = 0x3e4ccccd;
    _DAT_0067e3d8 = 0x3e4ccccd;
    _DAT_0067e3f0 = 0x3e19999a;
    _DAT_0067e404 = 0x3e19999a;
    _DAT_0067e418 = 0x3e19999a;
    _DAT_0067e430 = 0x3dcccccd;
    _DAT_0067e444 = 0x3dcccccd;
    _DAT_0067e458 = 0x3dcccccd;
    puVar2 = &DAT_0067df70;
    puVar3 = &DAT_0067df30;
    iVar1 = 0x14;
    do {
      FUN_004a16d0(puVar3,puVar2);
      puVar2 = puVar2 + 0x40;
      puVar3 = puVar3 + -0x40;
      iVar1 = iVar1 + -1;
    } while (iVar1 != 0);
    DAT_0067e4cc = '\x01';
  }
  return;
}

