/*
 * FUN_0042cdb8 at 0042cdb8
 * undefined * __register FUN_0042cdb8(int * param_1, int * param_2)
 * Address ranges: 0042cdb8-0042ce5d;0042ce76-0042cfbe
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined * FUN_0042cdb8(int *param_1,int *param_2)

{
  byte bVar1;
  byte bVar2;
  char cVar3;
  undefined *puVar4;
  uint uVar5;
  undefined4 uVar6;
  undefined3 uVar7;
  uint uVar8;
  
  puVar4 = (undefined *)FUN_0042a58c(param_1,param_2);
  if ((param_1[9] == 0) && (param_1[0x59] == 0)) {
    puVar4 = *(undefined **)(DAT_0047d770 + 0x24);
    param_2[7] = (int)puVar4;
    param_2[1] = param_2[1] & 0xbffcffff;
  }
  param_2[9] = 8;
  if (((*(byte *)(param_1 + 8) & 0x10) == 0) || (param_1[9] != 0)) {
    if ((byte)((char)param_1[0x86] - 1U) < 2) {
      param_2[3] = -0x80000000;
      param_2[4] = -0x80000000;
    }
    bVar1 = *(byte *)(param_1 + 0x84);
    uVar8 = (uint)bVar1;
    bVar2 = *(byte *)((int)param_1 + 0x211);
    if ((*(char *)((int)param_1 + 0x217) == '\x01') && ((bVar2 == 0 || (bVar2 == 3)))) {
      bVar2 = 2;
    }
    uVar5 = (uint)bVar2;
    switch(uVar5) {
    case 0:
      if ((param_1[9] == 0) && (param_1[0x59] == 0)) {
        param_2[1] = param_2[1] | 0x80000000;
      }
      uVar8 = 0;
      break;
    case 1:
    case 4:
      param_2[1] = param_2[1] | 0xc00000;
      break;
    case 2:
    case 5:
      param_2[1] = param_2[1] | 0xc40000;
      if (((char)param_1[0x86] == '\x01') || (uVar5 = 0, (char)param_1[0x86] == '\x03')) {
        uVar5 = 0;
        param_2[5] = -0x80000000;
        param_2[6] = -0x80000000;
      }
      break;
    case 3:
      param_2[1] = param_2[1] | 0x80c00000;
      param_2[2] = 0x101;
      FUN_00442780(param_1,(uint *)(param_2 + 2));
      puVar4 = PTR_DAT_0047c7a0;
      if (*PTR_DAT_0047c7a0 == '\0') {
        puVar4 = (undefined *)(param_2[1] | 0x400080);
        param_2[1] = (int)puVar4;
      }
      uVar5 = CONCAT31((int3)((uint)puVar4 >> 8),bVar1) & 0xffffff09;
      param_2[9] = 0x2808;
      uVar8 = uVar5;
    }
    uVar5 = uVar5 & 0xffffff00;
    if ((byte)(bVar2 - 4) < 2) {
      param_2[2] = 0x80;
      uVar6 = FUN_00442780(param_1,(uint *)(param_2 + 2));
      uVar5 = CONCAT31((int3)((uint)uVar6 >> 8),(char)uVar8) & 0xffffff01;
      uVar8 = uVar5;
    }
    uVar7 = (undefined3)(uVar5 >> 8);
    puVar4 = (undefined *)CONCAT31(uVar7,bVar2 - 3);
    if (bVar2 < 3) {
      if ((*(char *)((int)param_1 + 0x217) != '\x01') || ((uVar8 & 1) != 0)) {
        if ((uVar8 & 2) != 0) {
          param_2[1] = param_2[1] | 0x20000;
        }
        if ((uVar8 & 4) != 0) {
          param_2[1] = param_2[1] | 0x10000;
        }
      }
      cVar3 = *(char *)((int)param_1 + 0x213);
      puVar4 = (undefined *)CONCAT31(uVar7,cVar3);
      if (cVar3 == '\x01') {
        param_2[1] = param_2[1] | 0x20000000;
      }
      else if (cVar3 == '\x02') {
        param_2[1] = param_2[1] | 0x1000000;
      }
    }
    else {
      *(undefined1 *)((int)param_1 + 0x213) = 0;
    }
    if ((uVar8 & 1) != 0) {
      param_2[1] = param_2[1] | 0x80000;
    }
    if ((uVar8 & 8) != 0) {
      param_2[2] = param_2[2] | 0x400;
    }
    if ((*(byte *)((int)param_1 + 0x21) & 2) != 0) {
      param_2[1] = param_2[1] & 0xff3fffff;
    }
    if (*(char *)((int)param_1 + 0x217) == '\x01') {
      puVar4 = &DAT_00406738;
      param_2[10] = (int)&DAT_00406738;
    }
  }
  else {
    param_2[1] = param_2[1] | 0xcf0000;
  }
  return puVar4;
}

