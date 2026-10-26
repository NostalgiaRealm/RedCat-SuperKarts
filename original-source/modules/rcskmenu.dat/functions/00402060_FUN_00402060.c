/*
 * FUN_00402060 at 00402060
 * uint * __register FUN_00402060(uint param_1)
 * Address ranges: 00402060-00402153
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint * FUN_00402060(uint param_1)

{
  uint *puVar1;
  uint *puVar2;
  undefined4 uVar3;
  uint uVar4;
  
  while ((puVar1 = DAT_0047d484, puVar2 = DAT_0047d47c, (int)DAT_0047d47c[2] < (int)param_1 &&
         (uVar4 = DAT_0047d484[2], puVar2 = DAT_0047d484, (int)uVar4 < (int)param_1))) {
    DAT_0047d484[2] = param_1;
    puVar2 = puVar1;
    do {
      puVar2 = (uint *)puVar2[1];
    } while ((int)puVar2[2] < (int)param_1);
    DAT_0047d484[2] = uVar4;
    puVar1 = puVar2;
    if ((puVar2 != DAT_0047d484) ||
       (((int)param_1 < 0x1001 &&
        (puVar2 = (uint *)FUN_00402034(param_1), puVar1 = DAT_0047d484, puVar2 != (uint *)0x0))))
    break;
    uVar3 = FUN_00401fd4(param_1);
    puVar2 = DAT_0047d48c;
    if ((char)uVar3 == '\0') {
      return (uint *)0x0;
    }
    if ((int)param_1 <= DAT_0047d488) {
      DAT_0047d488 = DAT_0047d488 - param_1;
      if (DAT_0047d488 < 0xc) {
        param_1 = param_1 + DAT_0047d488;
        DAT_0047d488 = 0;
      }
      DAT_0047d48c = (uint *)((int)DAT_0047d48c + param_1);
      *puVar2 = param_1 | 2;
      _DAT_0047d424 = _DAT_0047d424 + 1;
      _DAT_0047d428 = _DAT_0047d428 + (param_1 - 4);
      return puVar2 + 1;
    }
  }
  DAT_0047d484 = puVar1;
  FUN_00401c24((int *)puVar2);
  uVar4 = puVar2[2];
  if ((int)(uVar4 - param_1) < 0xc) {
    if (puVar2 == DAT_0047d484) {
      DAT_0047d484 = (uint *)puVar2[1];
    }
    *(uint *)((int)puVar2 + uVar4) = *(uint *)((int)puVar2 + uVar4) & 0xfffffffe;
  }
  else {
    FUN_00401e74((uint *)((int)puVar2 + param_1),uVar4 - param_1);
    uVar4 = param_1;
  }
  *puVar2 = uVar4 | 2;
  _DAT_0047d424 = _DAT_0047d424 + 1;
  _DAT_0047d428 = _DAT_0047d428 + (uVar4 - 4);
  return puVar2 + 1;
}

