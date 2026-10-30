#!/usr/bin/env python3
"""Convert original WinHelp topics with helpdeco; no replacement help prose."""
import argparse
import hashlib
import html
import json
import re
import shutil
import subprocess
import tempfile
from pathlib import Path
from urllib.parse import quote
from PIL import Image
from lib.winhelp_navigation import read_winhelp_navigation

ROOT=Path(__file__).resolve().parents[1]
DEFAULT_SOURCE=Path('/home/rick/Games/redcat-superkarts/drive_c/Program Files (x86)/Davilex/RedCat Super Karts/data/RCSK.HLP')
TOKEN=re.compile(r"\\([a-zA-Z]+)(-?\d+)? ?|\\'([0-9a-fA-F]{2})|\\(.)|([{}])|([^\\{}]+)")
IMAGE=re.compile(r'\{(bmc|bml|bmr)\s+([^{}]+)\}')
COLORS={1:'#000080',2:'#000000',3:'#800080',4:'#008000'}
STYLE={'bold':False,'italic':False,'underline':False,'font':1,'size':20,'color':1,'indent':0}

def sha(data):return hashlib.sha256(data).hexdigest()
def write_json(path,value):
    path.parent.mkdir(parents=True,exist_ok=True)
    path.write_text(json.dumps(value,ensure_ascii=False,indent=2)+'\n',encoding='utf8')

def rtf_tree(text):
    """Small strict RTF tokenizer; groups restore character/paragraph state."""
    root=[];stack=[root];end=0
    for match in TOKEN.finditer(text):
        if match.start()!=end:raise ValueError(f'Unparsed RTF at {end}')
        end=match.end();word,number,hexbyte,symbol,brace,literal=match.groups()
        if brace=='{':
            child=[];stack[-1].append(child);stack.append(child)
        elif brace=='}':
            if len(stack)==1:raise ValueError('Unbalanced RTF closing group')
            stack.pop()
        elif word:stack[-1].append(('control',word,int(number) if number is not None else None))
        elif hexbyte:stack[-1].append(('text',bytes.fromhex(hexbyte).decode('cp1252')))
        elif symbol:stack[-1].append(('text',{'~':'\u00a0','-':'\u00ad','_':'\u2011'}.get(symbol,symbol)))
        else:stack[-1].append(('text',literal.replace('\r','').replace('\n','')))
    if len(stack)!=1 or end!=len(text):raise ValueError('Incomplete RTF parse')
    return root

def plain(nodes):
    return ''.join(plain(n) if isinstance(n,list) else n[1] if n[0]=='text' else '' for n in nodes)

class HelpReader:
    def __init__(self):
        self.topics=[];self.controls=set();self.reset()
    def reset(self):
        self.topic={'title':'','id':'','keywords':[],'blocks':[],'links':[]}
        self.runs=[];self.row=None;self.cell=[];self.table=None
    def paragraph(self):
        if self.runs:
            block={'kind':'paragraph','runs':self.runs,'indent':self.runs[0]['style']['indent']}
            if self.row is not None:self.cell.append(block)
            else:self.topic['blocks'].append(block)
        self.runs=[]
    def end_cell(self):
        self.paragraph()
        if self.row is None:raise ValueError('RTF cell outside row')
        self.row.append(self.cell);self.cell=[]
    def end_row(self):
        self.paragraph()
        if self.cell:self.end_cell()
        if self.table is None:
            self.table={'kind':'table','rows':[]};self.topic['blocks'].append(self.table)
        self.table['rows'].append(self.row);self.row=None
    def page(self):
        self.paragraph()
        if self.row is not None:raise ValueError('Unclosed RTF table')
        if self.topic['id']:
            if not self.topic['title']:raise ValueError('Topic without original title')
            self.topics.append(self.topic)
        elif self.topic['blocks']:raise ValueError('Visible content outside identified topic')
        self.reset()
    def link(self,value):
        raw=value.strip()
        # '*' preserves the authored font; the binary opcode distinguishes
        # jumps from popups. Neither macros nor external commands execute.
        target=raw.lstrip('*')
        if not re.fullmatch(r'[\w.]+',target):
            raise ValueError(f'Unsupported WinHelp target: {raw!r}')
        selected=[]
        for run in reversed(self.runs):
            if run['style']['underline']:selected.append(run)
            elif run['text'].strip():break
        if not selected:raise ValueError(f'WinHelp link without underlined label: {raw}')
        for run in selected:run['link']=target;run['linkIndex']=len(self.topic['links'])
        self.topic['links'].append({'target':target,'raw':raw})
    def walk(self,nodes,state=None):
        state=dict(STYLE if state is None else state)
        for node in nodes:
            if isinstance(node,list):
                first=next((n for n in node if not (isinstance(n,tuple) and n[0]=='text' and not n[1].strip())),None)
                destination=first[1] if isinstance(first,tuple) and first[0]=='control' else ''
                if destination in ['fonttbl','colortbl','stylesheet','up']:continue
                if destination=='footnote':
                    text=plain(node).strip();marker=text[:1];text=text[1:].strip()
                    if marker=='$':self.topic['title']=text
                    elif marker=='#':self.topic['id']=text
                    elif marker=='K':self.topic['keywords']+=text.split(';')
                    else:raise ValueError(f'Unknown WinHelp footnote {marker}')
                elif destination=='v':self.link(plain(node))
                else:self.walk(node,state)
                continue
            if node[0]=='text':
                if node[1]:
                    if self.runs and self.runs[-1]['style']==state and not self.runs[-1].get('link'):
                        self.runs[-1]['text']+=node[1]
                    else:self.runs.append({'text':node[1],'style':dict(state)})
                continue
            _,word,value=node;self.controls.add(word)
            if word=='plain':
                indent=state['indent'];state=dict(STYLE);state['indent']=indent
            elif word=='pard':state['indent']=0
            elif word in ['b','i','ul','uldb']:
                state[{'b':'bold','i':'italic','ul':'underline','uldb':'underline'}[word]]=value!=0
            elif word in ['f','fs','cf','li']:state[{'f':'font','fs':'size','cf':'color','li':'indent'}[word]]=value
            elif word=='par':self.paragraph()
            elif word=='page':self.page()
            elif word=='tab':self.runs.append({'text':'\t','style':dict(state)})
            elif word=='trowd':
                self.paragraph()
                if self.row is not None:raise ValueError('Nested RTF table row')
                if not self.topic['blocks'] or self.topic['blocks'][-1].get('kind')!='table':self.table=None
                self.row=[];self.cell=[]
            elif word=='cell':self.end_cell()
            elif word=='row':self.end_row()
            elif word not in ['rtf','ansi','deff','sa','sb','fi','tx','keepn','sl','qc','intbl','trgaph','trleft','cellx']:
                raise ValueError(f'Unsupported visible RTF control {word}')

def render_topic(topic,images):
    referenced=[];plain_paragraphs=[]
    def paragraph(block):
        runs=[{**r,'style':dict(r['style'])} for r in block['runs']]
        while runs and not runs[0]['text'].strip():runs.pop(0)
        bullet=bool(runs and runs[0]['style']['font']==3 and runs[0]['text'].startswith('§'))
        if bullet:runs[0]['text']=runs[0]['text'][1:]
        while runs and not runs[0]['text'].strip():runs.pop(0)
        if not runs:return '',False,0
        output=[];texts=[]
        for run in runs:
            text=run['text'];style=run['style'];parts=[];end=0
            for match in IMAGE.finditer(text):
                parts.append(html.escape(text[end:match.start()]))
                source=match[2].strip().lower()
                if source not in images:raise ValueError(f'Unresolved original help image {source}')
                im=images[source];referenced.append(im['file'])
                parts.append(f'<img src="{html.escape(im["file"],quote=True)}" width="{im["width"]}" height="{im["height"]}" alt="" data-source="{source}">')
                end=match.end()
            parts.append(html.escape(text[end:]))
            value=''.join(parts).replace('\t',' ')
            if not value:continue
            texts.append(IMAGE.sub('',text).replace('\t',' '))
            if style['bold']:value=f'<strong>{value}</strong>'
            if style['italic']:value=f'<em>{value}</em>'
            if run.get('link'):
                target=run['link']
                link=topic['links'][run['linkIndex']]
                value=f'<a href="#help-{quote(target)}" data-help-topic="{html.escape(target,quote=True)}" data-help-context="{link["contextId"]}" data-help-kind="{link["kind"]}">{value}</a>'
            elif style['underline']:value=f'<u>{value}</u>'
            # Only fixed CSS properties and parsed integers enter generated styles.
            value=f'<span style="font-size:{style["size"]/2:g}pt;color:{COLORS.get(style["color"],"#000000")}">{value}</span>'
            output.append(value)
        plain_paragraphs.append(''.join(texts).strip())
        return ''.join(output),bullet,block['indent']
    output=[];list_open=False
    for block in topic['blocks']:
        if block['kind']=='table':
            if list_open:output.append('</ul>');list_open=False
            output.append('<table><tbody>')
            for row in block['rows']:
                output.append('<tr>')
                for cell in row:
                    values=[paragraph(p)[0] for p in cell]
                    output.append('<td>'+''.join(f'<p>{v}</p>' for v in values if v)+'</td>')
                output.append('</tr>')
            output.append('</tbody></table>')
        else:
            value,bullet,indent=paragraph(block)
            if not value:continue
            if bullet:
                if not list_open:output.append('<ul>');list_open=True
                output.append(f'<li style="margin-left:{max(0,indent-275)/20:g}pt">{value}</li>')
            else:
                if list_open:output.append('</ul>');list_open=False
                output.append(f'<p>{value}</p>')
    if list_open:output.append('</ul>')
    return ''.join(output),'\n'.join(plain_paragraphs),list(dict.fromkeys(referenced))

def main():
    parser=argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--source',type=Path,default=DEFAULT_SOURCE)
    parser.add_argument('--helpdeco',type=Path,default=ROOT/'work/helpdeco/gcc/helpdeco')
    parser.add_argument('--raw',type=Path,default=ROOT/'raw/help')
    parser.add_argument('--output',type=Path,default=ROOT/'public/assets/help')
    args=parser.parse_args()
    exe=args.helpdeco
    if not exe.is_file():
        found=shutil.which('helpdeco')
        if found:exe=Path(found)
        else:raise SystemExit('helpdeco is required. Build work/helpdeco/gcc/helpdeco or pass --helpdeco. Existing help output is not accepted as a successful rebuild.')
    args.raw.mkdir(parents=True,exist_ok=True);args.output.mkdir(parents=True,exist_ok=True)
    source=args.source.resolve();cmd=[str(exe.resolve()),str(source),'-y']
    navigation=read_winhelp_navigation(source)
    if navigation['macros'] or navigation['hasTopicWindowMap'] or navigation['bitmapHotspotCount']:
        raise ValueError('Unexpected active WinHelp macro, window map or image hotspot')
    stem=source.stem
    extracted_names=[]
    with tempfile.TemporaryDirectory(prefix='helpdeco-',dir=args.raw) as staging:
        result=subprocess.run(cmd,cwd=staging,capture_output=True,text=True,encoding='cp1252')
        log=result.stdout+result.stderr
        (args.raw/'helpdeco.log').write_text(log,encoding='utf8')
        if result.returncode:raise SystemExit(f'helpdeco failed ({result.returncode}); see {args.raw}/helpdeco.log')
        if not all((Path(staging)/(stem+suffix)).is_file() for suffix in ['.rtf','.hpj']):
            raise SystemExit('helpdeco did not produce fresh RTF and HPJ; stale output is not accepted.')
        for generated in Path(staging).iterdir():
            if generated.is_file():
                shutil.copyfile(generated,args.raw/generated.name);extracted_names.append(generated.name)
    rtf=args.raw/(stem+'.rtf');hpj=args.raw/(stem+'.hpj')
    rtf_source=rtf.read_text(encoding='cp1252')
    reader=HelpReader();reader.walk(rtf_tree(rtf_source));reader.page()
    project=hpj.read_text(encoding='cp1252')
    mapping={m[1]:int(m[2]) for m in re.finditer(r'^([^\s=]+)\s+(\d+)\s*$',project,re.M)}
    title=re.search(r'^TITLE=(.*)$',project,re.M)[1]
    start=re.search(r'^CONTENTS=(.*)$',project,re.M)[1]
    images={}
    for source_image in sorted(args.raw/name for name in extracted_names if name.lower().endswith('.bmp')):
        target=args.output/'images'/(source_image.stem+'.png');target.parent.mkdir(exist_ok=True)
        with Image.open(source_image) as im:
            rgb=im.convert('RGB');rgb.save(target)
            with Image.open(target) as converted:
                if converted.convert('RGB').tobytes()!=rgb.tobytes():raise ValueError('Lossy help image conversion')
            images[source_image.name.lower()]={'file':'assets/help/images/'+target.name,'width':im.width,'height':im.height,
                'sourceSHA256':sha(source_image.read_bytes()),'pixelSHA256':sha(rgb.tobytes())}
    native_topics={context:topic for topic in navigation['topics'] for context in topic['contextIds']}
    topics=[];ids={t['id'] for t in reader.topics}
    for topic in reader.topics:
        native=native_topics[mapping[topic['id']]]
        if native['title']!=topic['title'] or len(native['links'])!=len(topic['links']) or native['macros']:
            raise ValueError('RTF topic does not agree with original WinHelp records')
        # The raw keyword B-tree is authoritative: helpdeco's recovered RTF
        # footnotes can attach keywords to the wrong topic on this host.
        topic['keywords']=native['keywords']
        for link,original in zip(topic['links'],native['links']):
            if link['target'] not in ids:raise ValueError(f'Unresolved topic {link["target"]}')
            context=mapping[link['target']]
            if original['kind']!='jump' or original['windowTarget'] is not None or original['externalFile'] is not None:
                raise ValueError('Unexpected WinHelp popup, window or external destination')
            if context not in original['targetContextIds']:
                raise ValueError('RTF destination does not agree with original WinHelp hash')
            link.update({'contextId':context,'kind':original['kind'],'preserveFont':original['preserveFont'],
                         'targetHash':original['targetHash'],'opcode':original['opcode']})
        body,text,refs=render_topic(topic,images)
        topics.append({k:topic[k] for k in ['id','title','keywords','links']}|
                      {'contextId':mapping[topic['id']],'contextHashes':native['contextHashes'],
                       'browsePrevious':native['browsePrevious'],'browseNext':native['browseNext'],
                       'topicOffset':native['topicOffset'],'html':body,'text':text,'images':refs})
    if set(mapping)!=ids:raise ValueError('HPJ context map does not match RTF topics')
    if set(native_topics)!=set(mapping.values()):raise ValueError('HPJ map does not match original CTXOMAP')
    if next(t['topicOffset'] for t in topics if t['id']==start)!=navigation['contentsTopicOffset']:
        raise ValueError('HPJ Contents does not match original SYSTEM record')
    image_instances=sum(t['html'].count('<img ') for t in topics)
    if image_instances!=len(re.findall(r'\\\{bm[clr] ',rtf_source)):
        raise ValueError('Original RTF image reference was lost')
    cells=sum(t['html'].count('<td>') for t in topics)
    if cells!=len(re.findall(r'\\cell(?![a-z])',rtf_source)):
        raise ValueError('Original RTF table cell was lost')
    baggage=[]
    for source_audio in sorted(args.raw/name for name in extracted_names if name.lower().endswith('.wav')):
        target=args.output/source_audio.name.lower();shutil.copyfile(source_audio,target)
        baggage.append({'file':'assets/help/'+target.name,'sourceSHA256':sha(source_audio.read_bytes())})
    # Helpdeco recovers context names by hash guessing; numeric map is authoritative.
    limits=['Context aliases may be helpdeco hash guesses; numeric contexts and link hashes are checked directly against the original HLP.',
            'Browser window layout adapts to the viewport; native Windows window-manager placement is not emulated.',
            'The secondary window and baggage WAV are defined but have no activation in the authored help records.']
    warnings=[line for line in log.splitlines() if re.search(r'warn|missing|browse|error|problems|bad',line,re.I)]
    data={'schema':2,'title':title,'startTopic':start,'topics':topics,
          'contextMap':{str(t['contextId']):t['id'] for t in topics},'images':images,'baggage':baggage,
          'keywordIndex':navigation['keywords'],'windows':navigation['windows'],
          'navigation':{'browseLinks':sum(t['browsePrevious'] is not None or t['browseNext'] is not None for t in topics),
                        'popupLinks':0,'secondaryWindowLinks':0,'bitmapHotspots':navigation['bitmapHotspotCount'],
                        'topicRecords':navigation['topicRecordCount'],'source':'Original |TOPIC, |CTXOMAP, |CONTEXT, |KWBTREE, |KWDATA and |SYSTEM'},
          'presentation':{'fontFamily':'Arial','backgroundRGB':[254,255,139],
                          'source':'RTF font1 and HPJ [WINDOWS] main background'},
          'source':{'path':str(source),'sha256':sha(source.read_bytes()),'rtfSHA256':sha(rtf.read_bytes()),
                    'hpjSHA256':sha(hpj.read_bytes()),'toolSHA256':sha(exe.read_bytes()),
                    'toolRepository':'https://github.com/pmachapman/helpdeco',
                    'testedToolCommit':'785273788af17fde4fba7df7162d547f8645d7d8'},
          'warnings':warnings,'limitations':limits}
    write_json(args.output/'topics.json',data)
    write_json(ROOT/'docs/evidence/help-validation.json',{'status':'passed','sourceSHA256':data['source']['sha256'],
        'topics':len(topics),'images':len(images),'internalLinks':sum(len(t['links']) for t in topics),
        'tables':sum(t['html'].count('<table>') for t in topics),'tableCells':cells,
        'imageReferences':image_instances,'imagesPixelExact':True,
        'navigation':data['navigation'],'keywords':len(data['keywordIndex']),
        'unresolvedLinks':0,'unresolvedImages':0,'warnings':warnings,'limitations':limits})
    print(f'Prepared {len(topics)} original help topics, {len(images)} pixel-exact images and {sum(len(t["links"]) for t in topics)} internal links.')
if __name__=='__main__':main()
