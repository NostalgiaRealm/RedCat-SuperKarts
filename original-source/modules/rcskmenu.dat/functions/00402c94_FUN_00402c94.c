/*
 * FUN_00402c94 at 00402c94
 * undefined __register FUN_00402c94(uint param_1, uint param_2, undefined1 * param_3)
 * Address ranges: 00402c94-00402ce9
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00402c94(uint param_1,uint param_2,undefined1 *param_3)

{
  byte bVar1;
  byte bVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  byte *pbVar7;
  
  uVar5 = param_2 & 0xff;
  uVar6 = param_1 >> 8 & 0xff;
  for (uVar3 = uVar6; uVar3 != 0; uVar3 = uVar3 - 1) {
    *param_3 = 0;
    param_3 = param_3 + 1;
  }
  if (uVar6 * 8 <= uVar5) {
    uVar5 = uVar6 * 8 - 1;
  }
  if ((param_1 & 0xff) <= uVar5) {
    bVar1 = -1 << ((byte)param_1 & 7);
    uVar3 = (param_1 & 0xff) >> 3;
    bVar2 = 0xff >> (~(byte)uVar5 & 7);
    pbVar7 = param_3 + (uVar3 - uVar6);
    iVar4 = (uVar5 >> 3) - uVar3;
    if (iVar4 == 0) {
      *pbVar7 = bVar1 & bVar2;
    }
    else {
      *pbVar7 = bVar1;
      while( true ) {
        pbVar7 = pbVar7 + 1;
        iVar4 = iVar4 + -1;
        if (iVar4 == 0) break;
        *pbVar7 = 0xff;
      }
      *pbVar7 = bVar2;
    }
  }
  return;
}

