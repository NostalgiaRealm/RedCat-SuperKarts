/*
 * FUN_004477c0 at 004477c0
 * undefined FUN_004477c0(void)
 * Address ranges: 004477c0-00447898
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_004477c0(void)

{
  char cVar1;
  uint uVar2;
  uint uVar3;
  char *pcVar4;
  char *pcVar5;
  undefined1 local_3d;
  undefined1 *local_3c;
  undefined1 local_38 [4];
  char *local_34;
  uint local_30;
  undefined4 local_2c;
  undefined **local_28 [3];
  undefined1 local_1c;
  void *pvStack_c;
  undefined1 *puStack_8;
  int local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_004cd790;
  pvStack_c = ExceptionList;
  local_38[0] = local_3d;
  uVar2 = 0xffffffff;
  pcVar4 = s_invalid_bitset<N>_position_004efd00;
  do {
    if (uVar2 == 0) break;
    uVar2 = uVar2 - 1;
    cVar1 = *pcVar4;
    pcVar4 = pcVar4 + 1;
  } while (cVar1 != '\0');
  uVar2 = ~uVar2 - 1;
  local_34 = (char *)0x0;
  local_30 = 0;
  local_2c = 0;
  ExceptionList = &pvStack_c;
  cVar1 = FUN_0040b600(uVar2,1);
  if (cVar1 != '\0') {
    pcVar4 = s_invalid_bitset<N>_position_004efd00;
    pcVar5 = local_34;
    for (uVar3 = uVar2 >> 2; uVar3 != 0; uVar3 = uVar3 - 1) {
      *(undefined4 *)pcVar5 = *(undefined4 *)pcVar4;
      pcVar4 = pcVar4 + 4;
      pcVar5 = pcVar5 + 4;
    }
    for (uVar3 = uVar2 & 3; uVar3 != 0; uVar3 = uVar3 - 1) {
      *pcVar5 = *pcVar4;
      pcVar4 = pcVar4 + 1;
      pcVar5 = pcVar5 + 1;
    }
    local_34[uVar2] = '\0';
    local_30 = uVar2;
  }
  local_4 = 0;
  local_3c = &DAT_005437b0;
  FUN_004bfdaf(&local_3c);
  local_4._0_1_ = 1;
  local_1c = local_38[0];
  FUN_0040b4f0(0);
  FUN_00412870(local_38,0,0xffffffff);
  local_4 = (uint)local_4._1_3_ << 8;
  local_28[0] = &PTR_FUN_004d3504;
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(local_28,&DAT_004d58b8);
}

