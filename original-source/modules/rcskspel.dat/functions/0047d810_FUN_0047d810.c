/*
 * FUN_0047d810 at 0047d810
 * undefined FUN_0047d810(void)
 * Address ranges: 0047d810-0047d8ec
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void __fastcall FUN_0047d810(int param_1)

{
  char cVar1;
  uint uVar2;
  uint uVar3;
  char *pcVar4;
  char *pcVar5;
  undefined1 local_1c [4];
  char *local_18;
  uint local_14;
  undefined4 local_10;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_004d10bf;
  local_c = ExceptionList;
  if (*(int *)(param_1 + 0x48) != 0) {
    uVar2 = 0xffffffff;
    pcVar4 = s_OnMouseLeave_004f8780;
    do {
      if (uVar2 == 0) break;
      uVar2 = uVar2 - 1;
      cVar1 = *pcVar4;
      pcVar4 = pcVar4 + 1;
    } while (cVar1 != '\0');
    uVar2 = ~uVar2 - 1;
    local_18 = (char *)0x0;
    local_14 = 0;
    local_10 = 0;
    ExceptionList = &local_c;
    cVar1 = FUN_0040b600(uVar2,1);
    if (cVar1 != '\0') {
      pcVar4 = s_OnMouseLeave_004f8780;
      pcVar5 = local_18;
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
      local_18[uVar2] = '\0';
      local_14 = uVar2;
    }
    local_4 = 0;
    (**(code **)(param_1 + 0x48))(param_1,local_1c,0);
    if (local_18 != (char *)0x0) {
      cVar1 = local_18[-1];
      if ((cVar1 != '\0') && (cVar1 != -1)) {
        local_18[-1] = cVar1 + -1;
        ExceptionList = local_c;
        return;
      }
      FUN_004bc150(local_18 + -1);
    }
  }
  ExceptionList = local_c;
  return;
}

