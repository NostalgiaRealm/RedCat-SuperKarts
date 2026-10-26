/*
 * FUN_00436b10 at 00436b10
 * undefined FUN_00436b10(void)
 * Address ranges: 00436b10-00436d04
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 __thiscall FUN_00436b10(int param_1,int param_2)

{
  uint uVar1;
  uint uVar2;
  int *piVar3;
  char cVar4;
  undefined1 *puVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  uint uVar9;
  byte *pbVar10;
  byte *pbVar11;
  bool bVar12;
  bool bVar13;
  int iStack_18;
  
  iVar8 = param_2;
  puVar5 = *(undefined1 **)(param_2 + 4);
  if (puVar5 == (undefined1 *)0x0) {
    puVar5 = &DAT_004d2404;
  }
  FUN_004afce0(s_CVoice__AddSample__s__004ebf28,puVar5);
  FUN_004371f0();
  cVar4 = FUN_00437550();
  if (cVar4 == '\0') {
    return 1;
  }
  FUN_004afce0(s_Effects_on_004ebf40);
  iVar6 = (*(code *)**(undefined4 **)(param_1 + 0x38))();
  iStack_18 = 0;
  if (0 < iVar6) {
    do {
      iVar7 = FUN_004365c0();
      puVar5 = *(undefined1 **)(iVar7 + 4);
      if (puVar5 == (undefined1 *)0x0) {
        puVar5 = &DAT_004d2404;
      }
      FUN_004afce0(s_Sample___s_004ebf4c,puVar5);
      iVar7 = FUN_004365c0();
      uVar1 = *(uint *)(iVar8 + 8);
      pbVar11 = &DAT_004d2404;
      if (*(byte **)(iVar8 + 4) != (byte *)0x0) {
        pbVar11 = *(byte **)(iVar8 + 4);
      }
      uVar2 = *(uint *)(iVar7 + 8);
      uVar9 = uVar2;
      if (uVar1 <= uVar2) {
        uVar9 = uVar1;
      }
      bVar12 = false;
      iVar8 = 0;
      bVar13 = true;
      pbVar10 = *(byte **)(iVar7 + 4);
      do {
        if (uVar9 == 0) break;
        uVar9 = uVar9 - 1;
        bVar12 = *pbVar10 < *pbVar11;
        bVar13 = *pbVar10 == *pbVar11;
        pbVar10 = pbVar10 + 1;
        pbVar11 = pbVar11 + 1;
      } while (bVar13);
      if (!bVar13) {
        iVar8 = (1 - (uint)bVar12) - (uint)(bVar12 != 0);
      }
      if (((iVar8 == 0) && (uVar1 <= uVar2)) && (uVar2 == uVar1)) {
        FUN_004afce0(s_Found_sample_004ebf58);
        puVar5 = *(undefined1 **)(param_2 + 4);
        if (puVar5 == (undefined1 *)0x0) {
          puVar5 = &DAT_004d2404;
        }
        FUN_004afce0(s_Voice__d__m_Voice____VOICE_EFFEC_004ebf68,*(undefined4 *)(param_1 + 0x40),
                     puVar5);
        param_2 = iStack_18;
        if (*(int *)(param_1 + 0x30) != 0) {
          piVar3 = *(int **)(param_1 + 0x20);
          if (piVar3 != *(int **)(param_1 + 0x1c)) {
            *(int **)(param_1 + 0x20) = piVar3 + 1;
            if (piVar3 + 1 == *(int **)(param_1 + 0x1c)) {
              FUN_0043a120(piVar3,&param_2);
              FUN_004398f0();
            }
            else if (piVar3 != (int *)0x0) {
              *piVar3 = iStack_18;
            }
            goto LAB_00436cc9;
          }
        }
        FUN_004398f0();
        iVar8 = *(int *)(param_1 + 0x20);
        *(int *)(param_1 + 0x20) = iVar8 + 4;
        FUN_0043a120(iVar8,&param_2);
LAB_00436cc9:
        *(int *)(param_1 + 0x30) = *(int *)(param_1 + 0x30) + 1;
        FUN_0043a020(0xffffffff);
        return 1;
      }
      iStack_18 = iStack_18 + 1;
      iVar8 = param_2;
    } while (iStack_18 < iVar6);
  }
  puVar5 = *(undefined1 **)(iVar8 + 4);
  if (puVar5 == (undefined1 *)0x0) {
    puVar5 = &DAT_004d2404;
  }
  FUN_004afce0(s_Voice__d_has_no_sample_called_pl_004ebfa0,*(undefined4 *)(param_1 + 0x40),puVar5);
  return 0;
}

