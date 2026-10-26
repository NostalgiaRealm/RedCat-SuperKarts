/*
 * FUN_0040d9c0 at 0040d9c0
 * undefined FUN_0040d9c0(void)
 * Address ranges: 0040d9c0-0040dbcc
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0040d9c0(int param_1,char param_2)

{
  char cVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  uint uVar5;
  uint uVar6;
  char *pcVar7;
  char *pcVar8;
  undefined4 uVar9;
  undefined1 *puVar10;
  undefined1 local_2c [4];
  char *local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined1 local_1c [4];
  int local_18;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_004ccd38;
  local_c = ExceptionList;
  if (((&DAT_00503ef4)[param_1 * 0x47] != 9) &&
     (ExceptionList = &local_c, FUN_0040dbd0(param_1), param_2 != '\0')) {
    iVar2 = FUN_00493a40(*(undefined4 *)(DAT_0053be28 * 0xd0 + 0x1c + DAT_0067ee20),
                         *(undefined4 *)
                          ((&DAT_00503ef0)[param_1 * 0x47] * 0xd0 + 0x1c + DAT_0067ee20));
    if (iVar2 < 0) {
      iVar2 = -iVar2;
    }
    if (iVar2 < 2) {
      FUN_004371f0();
      uVar3 = FUN_00437ea0(param_1);
      cVar1 = FUN_00438730(param_1);
      if (cVar1 == '\0') {
        uVar3 = FUN_004381d0(local_1c);
        local_4 = 2;
        FUN_004387a0(DAT_00508610,uVar3);
        if (local_18 == 0) {
          ExceptionList = local_c;
          return;
        }
        pcVar7 = (char *)(local_18 + -1);
        cVar1 = *(char *)(local_18 + -1);
        if ((cVar1 != '\0') && (cVar1 != -1)) {
          *pcVar7 = cVar1 + -1;
          ExceptionList = local_c;
          return;
        }
      }
      else {
        uVar4 = FUN_00438130(local_2c);
        local_4 = 0;
        uVar9 = uVar3;
        FUN_004371f0(uVar3,uVar4);
        FUN_00437b10(uVar9,uVar4);
        local_4 = 0xffffffff;
        if (local_28 != (char *)0x0) {
          cVar1 = local_28[-1];
          if ((cVar1 == '\0') || (cVar1 == -1)) {
            FUN_004bc150(local_28 + -1);
          }
          else {
            local_28[-1] = cVar1 + -1;
          }
        }
        param_2 = (char)uVar3;
        local_2c[0] = param_2;
        uVar5 = 0xffffffff;
        pcVar7 = s_CLAXON_004defd4;
        do {
          if (uVar5 == 0) break;
          uVar5 = uVar5 - 1;
          cVar1 = *pcVar7;
          pcVar7 = pcVar7 + 1;
        } while (cVar1 != '\0');
        uVar5 = ~uVar5 - 1;
        local_28 = (char *)0x0;
        local_24 = 0;
        local_20 = 0;
        cVar1 = FUN_0040b600(uVar5,1);
        if (cVar1 != '\0') {
          pcVar7 = s_CLAXON_004defd4;
          pcVar8 = local_28;
          for (uVar6 = uVar5 >> 2; uVar6 != 0; uVar6 = uVar6 - 1) {
            *(undefined4 *)pcVar8 = *(undefined4 *)pcVar7;
            pcVar7 = pcVar7 + 4;
            pcVar8 = pcVar8 + 4;
          }
          for (uVar6 = uVar5 & 3; uVar6 != 0; uVar6 = uVar6 - 1) {
            *pcVar8 = *pcVar7;
            pcVar7 = pcVar7 + 1;
            pcVar8 = pcVar8 + 1;
          }
          FUN_0040b5e0(uVar5);
        }
        puVar10 = local_2c;
        local_4 = 1;
        FUN_004371f0(uVar3,puVar10);
        FUN_00437b10(uVar3,puVar10);
        if (local_28 == (char *)0x0) {
          ExceptionList = local_c;
          return;
        }
        pcVar7 = local_28 + -1;
        cVar1 = local_28[-1];
        if ((cVar1 != '\0') && (cVar1 != -1)) {
          *pcVar7 = cVar1 + -1;
          ExceptionList = local_c;
          return;
        }
      }
      FUN_004bc150(pcVar7);
    }
  }
  ExceptionList = local_c;
  return;
}

