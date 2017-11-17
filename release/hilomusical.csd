<CsoundSynthesizer>
<CsOptions>
; Select audio/midi flags here according to platform
-odac      ;;;realtime audio out
;-iadc    ;;;uncomment -iadc if realtime audio input is needed too
; For Non-realtime ouput leave only the line below:
; -o gen49.wav -W ;;; for file output any platform
</CsOptions>
<CsInstruments>

sr = 44100 
ksmps = 32 
nchnls = 2 
0dbfs  = 1 

instr 1

kamp chnget "amp" ;creamos un canal en el que la amplitud vaya de 0 a 4
kfreq chnget "freq" ;creamos un canal en el que la frecuencia vaya de 0 a 1

;kcps = sr/ftlen(1)
asig oscil kamp, kfreq, 1
   outs asig, asig
   
endin
</CsInstruments>
<CsScore>
f 1 0 4194304 49 "isawthatgirl.mp3" 1.5 1	;read an audio file (using GEN49).

i 1 0 4747
</CsScore>
</CsoundSynthesizer>
<bsbPanel>
 <label>Widgets</label>
 <objectName/>
 <x>100</x>
 <y>100</y>
 <width>320</width>
 <height>240</height>
 <visible>true</visible>
 <uuid/>
 <bgcolor mode="nobackground">
  <r>255</r>
  <g>255</g>
  <b>255</b>
 </bgcolor>
</bsbPanel>
<bsbPresets>
</bsbPresets>
