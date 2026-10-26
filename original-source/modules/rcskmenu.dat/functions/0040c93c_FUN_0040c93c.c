/*
 * FUN_0040c93c at 0040c93c
 * undefined __register FUN_0040c93c(void)
 * Address ranges: 0040c93c-0040ca42
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0040c93c(void)

{
  char *pcVar1;
  unkbyte10 Var2;
  byte bVar3;
  undefined2 uVar4;
  uint uVar5;
  ushort uVar6;
  int iVar7;
  undefined2 *unaff_EBX;
  int unaff_EBP;
  float10 *unaff_ESI;
  short *psVar8;
  short *psVar9;
  byte bVar10;
  float10 fVar11;
  
  bVar10 = 0;
  uVar6 = *(ushort *)((int)unaff_ESI + 8);
  uVar5 = uVar6 & 0x7fff;
  if ((uVar6 & 0x7fff) == 0) {
LAB_0040c967:
    uVar6 = 0;
  }
  else {
    if (uVar5 != 0x7fff) {
      fVar11 = *unaff_ESI;
      *(int *)(unaff_EBP + -8) = ((int)((uVar5 - 0x3fff) * 0x4d10) >> 0x10) + 1;
      fVar11 = ABS(fVar11);
      FUN_00405a10(0x12 - *(int *)(unaff_EBP + -8));
      fVar11 = ROUND(fVar11);
      *(ushort *)(unaff_EBP + -4) =
           (ushort)(_DAT_0040c360 < fVar11) << 8 | (ushort)(NAN(_DAT_0040c360) || NAN(fVar11)) << 10
           | (ushort)(_DAT_0040c360 == fVar11) << 0xe;
      if ((*(ushort *)(unaff_EBP + -4) & 0x4100) != 0) {
        fVar11 = fVar11 / (float10)10;
        *(int *)(unaff_EBP + -8) = *(int *)(unaff_EBP + -8) + 1;
      }
      Var2 = to_bcd(fVar11);
      *(unkbyte10 *)(unaff_EBP + -0x1a) = Var2;
      iVar7 = 9;
      psVar8 = (short *)((int)unaff_EBX + 3);
      do {
        bVar3 = *(byte *)(unaff_EBP + -0x1b + iVar7);
        psVar9 = psVar8 + (uint)bVar10 * -2 + 1;
        *psVar8 = (CONCAT11(bVar3,bVar3 >> 4) & 0xfff) + 0x3030;
        iVar7 = iVar7 + -1;
        psVar8 = psVar9;
      } while (iVar7 != 0);
      *(undefined1 *)psVar9 = 0;
      uVar5 = *(int *)(unaff_EBP + -8) + *(int *)(unaff_EBP + 8);
      if ((int)uVar5 < 0) {
        uVar5 = 0;
        goto LAB_0040c967;
      }
      if (*(uint *)(unaff_EBP + 0xc) <= uVar5) {
        uVar5 = *(uint *)(unaff_EBP + 0xc);
      }
      if (uVar5 < 0x12) {
        if (*(byte *)((int)unaff_EBX + uVar5 + 3) < 0x35) goto LAB_0040ca1e;
        do {
          *(undefined1 *)((int)unaff_EBX + uVar5 + 3) = 0;
          if ((int)(uVar5 - 1) < 0) {
            *(undefined2 *)((int)unaff_EBX + 3) = 0x31;
            *(int *)(unaff_EBP + -8) = *(int *)(unaff_EBP + -8) + 1;
            break;
          }
          pcVar1 = (char *)((int)unaff_EBX + uVar5 + 2);
          *pcVar1 = *pcVar1 + '\x01';
          iVar7 = uVar5 + 2;
          uVar5 = uVar5 - 1;
        } while (0x39 < *(byte *)((int)unaff_EBX + iVar7));
      }
      else {
        uVar5 = 0x12;
LAB_0040ca1e:
        do {
          *(undefined1 *)((int)unaff_EBX + uVar5 + 3) = 0;
          if ((int)(uVar5 - 1) < 0) {
            bVar10 = 0;
            goto LAB_0040ca31;
          }
          iVar7 = uVar5 + 2;
          uVar5 = uVar5 - 1;
        } while (*(char *)((int)unaff_EBX + iVar7) == '0');
      }
      bVar10 = (byte)((ushort)*(undefined2 *)((int)unaff_ESI + 8) >> 8);
LAB_0040ca31:
      uVar4 = (undefined2)*(undefined4 *)(unaff_EBP + -8);
      goto LAB_0040ca34;
    }
    if ((((unkuint10)*unaff_ESI & 0x8000000000000000) != 0) &&
       ((*(int *)unaff_ESI != 0 || (*(int *)((int)unaff_ESI + 4) != -0x80000000)))) {
      uVar5 = 0x8000;
      goto LAB_0040c967;
    }
  }
  bVar10 = (byte)(uVar6 >> 8);
  uVar4 = (undefined2)uVar5;
  *(undefined1 *)((int)unaff_EBX + 3) = 0;
LAB_0040ca34:
  *unaff_EBX = uVar4;
  *(byte *)(unaff_EBX + 1) = bVar10 >> 7;
  return;
}

