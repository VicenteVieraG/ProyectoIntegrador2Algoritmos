import "../styles/main.css";
import "animate.css/animate.min.css";
import {AnimationOnScroll} from 'react-animation-on-scroll';

const SPIntro = () => {
	//Getting a css varible and modifying it
	//const n:string = getComputedStyle(document.documentElement).getPropertyValue("--opac");
	//document.documentElement.style.setProperty('--logo-color', newColor);
	return (
		<div className="SPPresentation">
			<div className="SPContainer">
				<AnimationOnScroll animateIn="animate__fadeIn" initiallyVisible={false} delay={2000} duration={3}>
					<p className="SPTitle">Primera Actividad Integradora</p>
				</AnimationOnScroll>
				<AnimationOnScroll animateIn="animate__fadeInUp" initiallyVisible={false} delay={2000} duration={3}>
					<label className="SP">Situación Problema:</label>
					<p className="SPText">
						Cuando se transmite información de un dispositivo a otro,
						se transmite una serie sucesiva de bits, que llevan una cabecera,
						datos y cola.

						Existe mucha gente mal intencionada, que puede interceptar estas
						transmisiones, modificar estas partes del envío, y enviarlas al 
						destinatario, incrustando sus propios scripts o pequeños programas 
						que pueden tomar cierto control del dispositivo que recibe la 
						información.
					</p>
					<label className="SP">Suponiendo que conocemos secuencias de bits de código mal intencionado:</label>
					<ul>
						<li><p className="SPText">¿serías capaz de identificarlo dentro del flujo de bits de una transmisión?</p></li>
						<li><p className="SPText">¿podremos identificar si el inicio de los datos se encuentra más adelante en el flujo de bits?</p></li>
					</ul>
					<p className="SPText">
						Si tuviéramos dos transmisiones de información y sospechamos que en ambas 
						han sido intervenidas y que traen el mismo código malicioso, 
						¿podríamos dar propuestas del código mal intencionado?
					</p>
				</AnimationOnScroll>
			</div>
		</div>
	)
}

export default SPIntro